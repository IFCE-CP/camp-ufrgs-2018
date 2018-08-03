#include <bits/stdc++.h>

using namespace std;
const int INF = 100000010;
int main()
{
    int m, n;
    while(cin >> m and m){
        cin >> n;
        int v[n];
        int dp[m+1];
        for(int i = 0; i < n; i++) cin >> v[i];
        dp[0] = 0;
        for(int i = 1; i <= m; i++){
            dp[i] = INF;
            for(int j = 0; j < n; j++){
                if(v[j] > i) continue;
                dp[i] = min(dp[i], dp[i-v[j]] + 1);
            }
        }
        if(dp[m] >= INF) cout << "Impossivel\n";
        else cout << dp[m] << endl;
    }
    return 0;
}