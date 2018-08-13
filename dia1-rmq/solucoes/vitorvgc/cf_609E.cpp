#include <bits/stdc++.h>

#define MAX 200100
#define LOG_MAX 20

using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

struct Edge {
    int u, v, w, id;

    bool operator<(const Edge other) const {
        return this->w < other.w;
    }
};

vector<pii> mst[MAX];
Edge e[MAX];
int n, m;
int p[MAX], rnk[MAX];
bool belongsMST[MAX];
int h[MAX], anc[MAX][LOG_MAX], mx[MAX][LOG_MAX];
ll ans[MAX];

int _find(int v) {
    return p[v] == v ? v : p[v] = _find(p[v]);
}

void _union(int u, int v) {
    rnk[u] > rnk[v] ? p[v] = u : p[u] = v;
    if(rnk[u] == rnk[v]) ++rnk[v];
}

ll findMST() {

    ll ans = 0;
    sort(e, e+m);
    for(int i = 0, q = 0; i < m && q < n-1; ++i) {
        int pu = _find(e[i].u);
        int pv = _find(e[i].v);
        if(pu != pv) {
            _union(pu, pv);
            ans += e[i].w;
            belongsMST[e[i].id] = true;
            mst[e[i].u].push_back(pii(e[i].v, e[i].w));
            mst[e[i].v].push_back(pii(e[i].u, e[i].w));
        }
    }
    return ans;
}

void dfs(int u, int p, int weight, int ha) {
    
    if(h[u] > -1) return;

    h[u] = ha;
    anc[u][0] = p;
    mx[u][0] = weight;
    for(auto v : mst[u])
        dfs(v.first, u, v.second, ha+1);
}

void build() {
    
    memset(h, -1, sizeof h);
    dfs(1, 0, 0, 0);
    for(int i = 1; i < LOG_MAX; ++i)
        for(int v = 1; v <= n; ++v) {
            anc[v][i] = anc[ anc[v][i-1] ][i-1];
            mx[v][i] = max(mx[v][i-1], mx[ anc[v][i-1] ][i-1]);
        }
}

int maxEdge(int u, int v) {
    
    int ans = 0;

    if(h[u] > h[v]) swap(u, v);

    for(int i = LOG_MAX-1; i >= 0; --i)
        if(h[v] - h[u] >= (1 << i)) {
            ans = max(ans, mx[v][i]);
            v = anc[v][i];
        }

    if(u == v) return ans;

    for(int i = LOG_MAX-1; i >= 0; --i)
        if(anc[u][i] != anc[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = anc[u][i], v = anc[v][i];
        }
    ans = max(ans, max(mx[u][0], mx[v][0]));

    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        e[i].id = i;
    }
    for(int i = 0; i <= n; ++i)
        p[i] = i, rnk[i] = 0;

    ll mstWeight = findMST();
    build();
    for(int i = 0; i < m; ++i)
        ans[e[i].id] = mstWeight + (belongsMST[e[i].id] ? 0 : e[i].w - maxEdge(e[i].u, e[i].v));
    for(int i = 0; i < m; ++i)
        printf("%I64d\n", ans[i]);
    return 0;
}

