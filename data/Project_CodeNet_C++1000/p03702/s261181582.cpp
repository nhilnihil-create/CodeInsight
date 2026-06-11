#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a,b,arr[N];
bool chk(ll cnt){
    ll rmv = cnt*b;
    ll req = 0;
    for(ll i=0;i<n;i++){
        ll val = arr[i] - rmv;
        ll extra = (val + a-b-1 )/(a-b);
        if(val>0)req+=extra;
    }
    return req<=cnt;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>a>>b;
    for(ll i=0;i<n;i++)cin>>arr[i];
    ll s=0,e=1e9;
    ll ans=1e10;
    while(s<=e){
        ll mid=(s+e)>>1;
        if(chk(mid))ans=min(ans,mid),e=mid-1;
        else s=mid+1;
    }
    cout<<ans;
}
