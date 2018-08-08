#include <bits/stdc++.h>

#define MAX 5010

using namespace std;

int dp[MAX] = {1, 1};

int main() {
    string s;
    while(cin >> s && s != "0") {
        int n = s.length();
        for(int i = 2; i <= n; ++i) {
            dp[i] = 0;
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            if(s[i-2] != '0' && (s[i-2]-'0')*10 + (s[i-1]-'0') <= 26)
                dp[i] += dp[i-2];
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
