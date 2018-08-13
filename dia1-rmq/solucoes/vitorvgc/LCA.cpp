#include <bits/stdc++.h>

#define MAX 1010
#define LOG_MAX 10

using namespace std;

vector<int> g[MAX];
int h[MAX], anc[MAX][LOG_MAX];

void dfs(int u, int p, int ha) {

    if(h[u] > -1) return;

    h[u] = ha;
    anc[u][0] = p;
    for(int v : g[u])
        dfs(v, u, ha + 1);
}

void build(int n) {

    memset(h, -1, sizeof h);
    dfs(1, 0, 0);
    for(int i = 1; i < LOG_MAX; ++i)
        for(int v = 1; v <= n; ++v)
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

int main() {
    int tests, n, q;
    scanf("%d", &tests);
    for(int t = 1; t <= tests; ++t) {
        scanf("%d", &n);
        for(int m, j, i = 1; i <= n; ++i)
            for(scanf("%d", &m); m--; ) {
                scanf("%d", &j);
                g[i].push_back(j);
                g[j].push_back(i);
            }

        build(n);
        printf("Case %d:\n", t);
        for(scanf("%d", &q); q--; ) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", lca(u, v));
        }
    }
    return 0;
}
