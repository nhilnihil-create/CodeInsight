#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    for(ll m=0;m<=n-1;m++){
        ll mn = c*(n-1-m) - d*m;
        ll mx = d*(n-1-m) - c*m;
        if(mn<=b-a && b-a<=mx)return cout<<"YES" , 0;
    }
    cout<<"NO";
}
