#include <bits/stdc++.h>

using namespace std;
int memo[21][11][160];

int solve(int n, int k, int s){
    if(!k) return s == 0;
    if(!n) return 0;
    if(memo[n][k][s] == -1){
        memo[n][k][s] = solve(n-1, k, s);
        if(s >= n && k)
            memo[n][k][s] += solve(n-1, k-1, s-n);
    }
    return memo[n][k][s]; 
}
int main()
{
    int n, k, s;
    while(cin >> n >> k >> s && n + k + s){
        memset(memo, -1, sizeof memo);
        cout << solve(n, k, s) << endl;
    }
    return 0;
}