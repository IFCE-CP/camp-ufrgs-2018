#include <bits/stdc++.h>

#define MAX 10100

using namespace std;

typedef long long ll;

ll v[MAX], dp[MAX];

int main() {
    int tests, n;
    scanf("%d", &tests);
    for(int t = 1; t <= tests; ++t) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);

        dp[1] = v[0];
        for(int i = 2; i <= n; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + v[i-1]);

        printf("Case %d: %lld\n", t, dp[n]);
    }
}
