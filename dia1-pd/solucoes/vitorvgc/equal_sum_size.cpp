#include <bits/stdc++.h>

using namespace std;

int memo[25][15][160];

int solve(int n, int k, int s) {
    
    if(s <= 0 || n <= 0) return 0;
    if(k == 1) return (n >= s);

    if(memo[n][k][s] > -1) return memo[n][k][s];

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += solve(i-1, k-1, s-i);

    return memo[n][k][s] = ans;
}

int main() {
    int n, k, s;
    memset(memo, -1, sizeof memo);
    while(scanf("%d %d %d", &n, &k, &s) && n|k|s)
        printf("%d\n", solve(n, k, s));
    return 0;
}
