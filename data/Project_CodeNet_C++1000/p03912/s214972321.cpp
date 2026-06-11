#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll ans,n,m,a[N],mod[N];
map<ll,ll> mp;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<n;i++)cin>>a[i],mod[a[i]%m]++,mp[a[i]]++;
    ans=mod[0]/2;
    mod[0]%=2;
    if(m%2==0)ans+=mod[m/2]/2,mod[m/2]%=2;
    for(ll i=1;i<m;i++){
        if(2*i==m)continue;
        ll have = min(mod[i] , mod[m-i]);
        ans+=have;
        mod[i]-=have;
        mod[m-i]-=have;
    }
    for(ll i=0;i<n;i++){
        ll have = min(mod[a[i]%m] , mp[a[i]])/2;
        if(have){
            ans+=have;
            mod[a[i]%m]-=2*have;
            mp[a[i]]-=2*have;
        }
    }
    cout<<ans;
}