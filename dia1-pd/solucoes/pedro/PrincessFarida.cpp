#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t, n, caso = 0;
    cin >> t;
    while(caso++ < t){
        cin >> n;
        if(!n){
            printf("Case %d: %lld\n", caso, 0);
            continue;
        }
        ll c[n+1];
        for(int i = 1; i <= n; i++)
            cin >> c[i];
        ll pm[n+1];
        pm[0] = 0;
        pm[1] = c[1];
        ll ans = c[1];
        for(int i = 2; i <= n; i++){
            ll dpi = c[i] + pm[i-2];
            pm[i] = max(pm[i-1], dpi);
            ans = max(ans, dpi);
        }
        printf("Case %d: %lld\n", caso, ans);
    }
    return 0;
}