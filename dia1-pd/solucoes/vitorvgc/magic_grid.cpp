#include <bits/stdc++.h>

#define INF 1000000000
#define MAX 510

using namespace std;

int g[MAX][MAX], memo[MAX][MAX];
int r, c;

int solve(int i, int j) {
    
    if(i >= r || j >= c) return INF;
    if(i == r-1 && j == c-1) return max(1, 1 - g[i][j]);

    if(memo[i][j] > -1) return memo[i][j];

    int mn = min(solve(i+1, j), solve(i, j+1));
    return memo[i][j] = max(1, mn - g[i][j]);
}

int main() {
    int t;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d", &r, &c);
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                scanf("%d", &g[i][j]);

        memset(memo, -1, sizeof memo);
        printf("%d\n", solve(0, 0));
    }
    return 0;
}
