#include <bits/stdc++.h>

#define MAXN 55
#define MAXM 1010

using namespace std;

int v[MAXN], w[MAXN], dp[MAXN][MAXM];

int main() {
    int c, f, t = 0;
    while(scanf("%d %d", &c, &f) && c|f) {
        for(int i = 0; i < f; ++i)
            scanf("%d %d", &w[i], &v[i]);

        for(int i = 1; i <= f; ++i)
            for(int j = 1; j <= c; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= w[i-1] && dp[i][j] < dp[i-1][j - w[i-1]] + v[i-1])
                    dp[i][j] = dp[i-1][j - w[i-1]] + v[i-1];
            }

        printf("Teste %d\n%d\n\n", ++t, dp[f][c]);
    }
    return 0;
}
