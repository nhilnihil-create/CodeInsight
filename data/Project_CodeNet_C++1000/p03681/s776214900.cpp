#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    if(abs(n-m) > 1){
        cout<<"0\n";
        return 0;
    }
    if(n > m) swap(n,m);
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans * i) % mod;
    }
    for(int i=1;i<=m;i++){
        ans = (ans * i) % mod;
    }
    if(n == m){
        ans = (ans * 2) % mod;
    }
    cout<<ans<<"\n";
    return 0;
}


