#include <bits/stdc++.h>

#define MAX 50100
#define LOG_MAX 20

using namespace std;

typedef pair<int,int> pii;

vector<pii> g[MAX];
int h[MAX], d[MAX], anc[MAX][LOG_MAX];

void dfs(int u, int p, int ha, int dist) {
    
    if(h[u] > -1) return;

    h[u] = ha;
    d[u] = dist;
    anc[u][0] = p;
    for(auto v : g[u])
        dfs(v.first, u, ha+1, dist + v.second);
}

void build(int n) {

    memset(h, -1, sizeof h);
    dfs(0, 0, 0, 0);
    for(int i = 1; i < LOG_MAX; ++i)
        for(int v = 0; v < n; ++v)
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
    return d[u] + d[v] - 2*d[lca(u, v)];
}

int main() {
    int n, q;
    scanf("%d", &n);
    for(int u, v, w, i = 0; i < n-1; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
    build(n);
    for(scanf("%d", &q); q--; ) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", dist(u, v));
    }
    return 0;
}
