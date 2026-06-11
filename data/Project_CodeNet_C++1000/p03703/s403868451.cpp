#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ft[2000005];
ll ls(ll x) { 
    return (x & (-x)); 
}
ll query(ll p) {
    ll sum = 0;
    for(; p; p -= ls(p)) sum += ft[p];
    return sum;
}

void update(ll p, ll v) {
	for(; p <= 2000005; p += ls(p)) ft[p] += v;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,i,q,x,y,i1,z,k,sum=0;
    cin>>n>>k;
    ll arr[n],ps[n+1];
    map<ll,ll>mp;
    vector<ll>v;
    ps[0]=0;
    v.push_back(0);
    for (i=0;i<n;i++){
        cin>>arr[i];
        arr[i]-=k;
        ps[i+1]=ps[i]+arr[i];
        v.push_back(ps[i+1]);
    }
    sort(v.begin(),v.end());
    for (i=0;i<v.size();i++){
        mp[v[i]]=i+1;
    }
    update(mp[0],1);
    for (i=1;i<=n;i++){
        //cout<<ps[i]<<' '<<mp[ps[i]]<<' '<<query(mp[ps[i]])<<'\n';
        sum+=query(mp[ps[i]]);
        update(mp[ps[i]],1);
    }
    cout<<sum<<'\n';
}
