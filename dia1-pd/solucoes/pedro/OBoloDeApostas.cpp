#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n){
        int apostas[n];
        for(int i = 0; i < n; i++)
            cin >> apostas[i];
        int ans, s;
        ans = s = 0;
        for(auto aposta: apostas){
            s = max(0, s + aposta);
            ans = max(s, ans);
        }
        if(ans) printf("The maximum winning streak is %d.\n", ans);
        else printf("Losing streak.\n");
    }
    return 0;
}