#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e2;

void solve(){
    int n, m; cin>>n>>m;
    ll a[n+1], b[n+1], c[m+1], d[m+1];

    for (int i=1; i<=n; i++) cin>>a[i]>>b[i];
    for (int i=1; i<=m; i++) cin>>c[i]>>d[i];

    for (int i=1; i<=n; i++){
        ll min = LONG_MAX, res;
        for (int j=1; j<=m; j++){
            ll x = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if(x<min){ min = x; res = j;}
        }
        cout<<res<<endl;
    }
}

int main(){
    solve();
    Bye;
}