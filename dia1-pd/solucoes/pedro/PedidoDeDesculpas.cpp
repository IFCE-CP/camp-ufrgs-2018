#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, f, teste =  0;
    while(cin >> c >> f && c+f){
        int w[f+1], v[f+1];
        for(int i = 1; i <= f; ++i)
            cin >> w[i] >> v[i];
        int dp[f+1][c+1];
        for(int i = 0; i <= f; i++)
            dp[i][0] = 0;
        for(int i = 0; i <= c; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= f; i++){
            for(int j = 1; j <= c; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= w[i])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
        printf("Teste %d\n", ++teste);
        printf("%d\n\n", dp[f][c]);
    }
    return 0;
}

/*
    dp[i][j] = 0, se i = 0 or j = 0
    dp[i][j] = dp[i-1][j]
    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]), se j >= w[i]

*/