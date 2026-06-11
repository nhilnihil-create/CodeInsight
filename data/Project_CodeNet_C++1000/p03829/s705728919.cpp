#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1000000007;

int main(){
    ll n,a,b;cin>>n>>a>>b;
    ll ans=0;
    ll x_b,x_a;cin>>x_b;
    for(int i=1;i<n;i++){
        cin>>x_a;
        ans+=min(b,(x_a-x_b)*a);
        x_b=x_a;
    }
    cout<<ans<<endl;
}