#include <bits/stdc++.h>

#define MAX 10100

using namespace std;

int v[MAX];

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        int ans = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            sum = max(0, sum + v[i]);
            ans = max(ans, sum);
        }
        if(ans == 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", ans);
    }
    return 0;
}
