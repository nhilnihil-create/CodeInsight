#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    ll n; cin>>n;

    ll t[n+1];
    for (ll i=1; i<=n; i++) cin>>t[i];

    ll m; cin>>m;
    ll p[m+1], x[m+1];
    for (ll i=1; i<=m; i++) cin>>p[i]>>x[i];

    for (ll i=1; i<=m; i++){
        ll sum = 0;
        for (ll j = 1; j<=n; j++){
            if(p[i] == j)
                sum += x[i];
            else sum += t[j];
        }
        cout<<sum<<endl;
    }

}

int main()
{
    solve();
    Bye;
}