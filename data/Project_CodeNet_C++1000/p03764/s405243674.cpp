#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> x(n+1), y(m+1);
    for(int i=1; i<=n; i++) cin >> x[i];
    for(int i=1; i<=m; i++) cin >> y[i];

    ll mod = 1e9+7;
    ll xs = 0, ys = 0;
    for(int i=1; i<=n; i++){
        xs += (2*i-n-1)*x[i];
    }
    for(int i=1; i<=m; i++){
        ys += (2*i-m-1)*y[i];
    }
    xs = xs%mod;  ys = ys%mod;
    cout << (xs*ys)%mod << endl;
}
