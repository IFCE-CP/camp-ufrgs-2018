#include <bits/stdc++.h>

#define MAXN 110
#define MAXM 50100
#define INF 1000000000

using namespace std;

int v[MAXN], memo[MAXN][MAXM];

int solve(int n, int m) {
    
    if(m == 0) return 0;
    if(m < 0 || n <= 0) return INF;

    if(memo[n][m] > -1) return memo[n][m];

    return memo[n][m] = min(solve(n-1, m), 1 + solve(n, m - v[n-1]));
}

int main() {
    int m, n;
    while(scanf("%d", &m) && m) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        memset(memo, -1, sizeof memo);
        int ans = solve(n, m);
        if(ans >= INF) printf("Impossivel\n");
        else printf("%d\n", ans);
    }
}
