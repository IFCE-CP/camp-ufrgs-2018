#include <bits/stdc++.h>

using namespace std;

const int INF = 100000010;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int g[n+1][m+1], dp[n+1][m+1];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> g[i][j];
        dp[n][m] = g[n][m] < 0 ? -g[n][m] + 1: 1;
        for(int i = n; i >= 1; i--){
            for(int j = m; j >= 1; j--){
                if(i == n && j == m) continue;
                int a, b;
                a = b = INF;
                if(i + 1 <= n) a = dp[i+1][j];
                if(j + 1 <= m) b = dp[i][j+1];
                int best = min(a, b);
                if(g[i][j] < 0) dp[i][j] = -g[i][j] + best;
                else dp[i][j] = max(1, best - g[i][j]);
                
            }
        }

        printf("%d\n", dp[1][1]);
    }
}