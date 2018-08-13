#include <bits/stdc++.h>

#define INF 1000000000ll

using namespace std;

typedef long long ll;

ll v[5010], memo[5010][1010];
int k, n;

ll solve(int i, int kr) {
    
    if(kr <= 0) return 0;
    if(i >= n-1) return INF;

    if(memo[i][kr] > -1) return memo[i][kr];

    ll ans = solve(i+1, kr);
    if(i - 3*(k - kr) > 0)
        ans = min(ans, (v[i] - v[i+1])*(v[i] - v[i+1]) + solve(i+2, kr-1));

    return memo[i][kr] = ans;
}

int main() {
    int t;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d", &k, &n);
        k += 8;
        for(int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);

        sort(v, v+n, [](ll a, ll b) { return a > b; });
        memset(memo, -1, sizeof memo);
        printf("%lld\n", solve(0, k));
    }
    return 0;
}
