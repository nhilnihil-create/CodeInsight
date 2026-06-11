#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
const int maxm=2e6+5;
ll n,x;
ll cal(ll a,ll b){
    if(b%a==0){//
        return (b/a*2-1)*a;
    }
    ll ans=b/a*2*a;
    ans+=cal(b%a,a);
    return ans;
}
signed main(){
    cin>>n>>x;
    ll a=x,b=n-x;
    if(a>b)swap(a,b);
    ll ans=cal(a,b)+n;//外面两条边的长度=x+(n-x)=n
    cout<<ans<<endl;
    return 0;
}
