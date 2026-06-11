#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    ll a,b,x;cin>>a>>b>>x;
    ll ans=0;
    if(a==0) ans=b/x+1;
    else ans=b/x-(a-1)/x;
    cout<<ans<<endl;
}