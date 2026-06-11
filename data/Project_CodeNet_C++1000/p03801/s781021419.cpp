#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5,mod=1e9+7;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}
ll ans[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    vector< pair<ll,ll> > a(n+1);
    for(ll i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
    sort(a.begin()+1,a.end(),cmp);
    ll cur=n;
    for(ll i=n;i>=1;i--){
        cur = min(cur,a[i].second);
        ans[cur]+=(a[i].first - a[i-1].first)*(n-(i-1));
    }
    for(ll i=1;i<=n;i++)cout<<ans[i]<<"\n";
}