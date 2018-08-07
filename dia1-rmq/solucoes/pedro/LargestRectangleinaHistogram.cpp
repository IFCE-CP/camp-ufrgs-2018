#include <bits/stdc++.h>

using namespace std;
#define MAXN 100010

long long h[MAXN];
long long tree[4*MAXN];

int n;

void build(int l, int r, int node){
    if(l == r){
        tree[node] = r;
    }
    else{
        int m = (l+r)/2;
        build(l, m, 2*node);
        build(m+1, r, 2*node+1);
        int r1 = tree[2*node];
        int r2 = tree[2*node+1];
        if(h[r1] < h[r2]) tree[node] = r1;
        else tree[node] = r2;
    }
}

long long query(int l, int r, int a, int b, int node){
    if(r < a || l > b) return -1;
    if(a <= l && r <= b) return tree[node];
    int m = (l+r)/2;
    int r1 = query(l, m, a, b, 2*node);
    int r2 = query(m+1, r,a, b, 2*node+1);
    if(r1 == -1) return r2;
    if(r2 == -1) return r1;
    if(h[r1] < h[r2]) return r1;
    return r2;
}


long long f(int l, int r){
    if(l > r) return 0;
    if(l == r) return h[l];
    int id_menor = query(0, n-1, l, r, 1);
    return max( (r-l+1) * h[id_menor], 
    max(f(l, id_menor-1), f(id_menor+1, r))
    );
}
int main(){
    while(cin >> n && n){
        for(int i = 0; i < n; i++)
            cin >> h[i];
        build(0, n-1, 1);
        cout << f(0, n-1) << endl;
    }
}