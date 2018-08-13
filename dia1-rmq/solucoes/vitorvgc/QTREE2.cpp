#include <bits/stdc++.h>

#define MAX 10100
#define LOG_MAX 15

using namespace std;

typedef pair<int,int> pii;

vector<pii> g[MAX];
int h[MAX], d[MAX], anc[MAX][LOG_MAX];

void dfs(int u, int p, int ha, int cost) {
    
    if(h[u] > -1) return;

    h[u] = ha;
    d[u] = cost;
    anc[u][0] = p;
    for(pii v : g[u])
        dfs(v.first, u, ha + 1, cost + v.second);
}

void build(int n) {
    
    memset(h, -1, sizeof h);
    memset(anc, -1, sizeof anc);
    dfs(1, 0, 0, 0);
    for(int i = 1; i < LOG_MAX; ++i)
        for(int v = 1; v <= n; ++v)
            if(anc[v][i-1] != -1)
                anc[v][i] = anc[anc[v][i-1]][i-1];
}

int lca(int u, int v) {
    
    if(h[u] > h[v]) swap(u, v);

    for(int i = LOG_MAX-1; i >= 0; --i)
        if(h[v] - h[u] >= (1 << i))
            v = anc[v][i];

    if(u == v) return u;

    for(int i = LOG_MAX-1; i >= 0; --i)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];

    return anc[u][0];
}

int dist(int u, int v) {
    int a = lca(u, v);
    return d[u] + d[v] - 2*d[a];
}

int kth(int u, int v, int k) {
    int a = lca(u, v);
    int t = h[u] + h[v] - 2*h[a] + 1;
    int w = u, dist = k-1;
    if(k > h[u] - h[a] + 1)
        w = v, dist = t - k;

    for(int i = LOG_MAX-1; i >= 0; --i)
        if(dist >= (1 << i))
            w = anc[w][i], dist -= (1 << i);

    return w;
}

int main() {
    int t, n;
    char command[10];
    for(scanf("%d", &t); t--; ) {
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i)
            g[i].clear();
        for(int u, v, w, i = 0; i < n-1; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back(pii(v, w));
            g[v].push_back(pii(u, w));
        }
        build(n);
        while(scanf("%s", command) && command[1] != 'O') {
            int u, v, k;
            scanf("%d %d", &u, &v);
            if(command[0] == 'D')
                printf("%d\n", dist(u, v));
            else if(command[0] == 'K') {
                scanf("%d", &k);
                printf("%d\n", kth(u, v, k));
            }
        }
        puts("");
    }
    return 0;
}
