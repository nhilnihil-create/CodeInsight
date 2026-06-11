#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
ll n,ans=1,cur;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        if(2*cur+1>x)ans*=(cur+1),ans%=mod,cur--;
        cur++;
    }
    while(cur>0)ans*=cur,ans%=mod,cur--;
    cout<<ans;
}