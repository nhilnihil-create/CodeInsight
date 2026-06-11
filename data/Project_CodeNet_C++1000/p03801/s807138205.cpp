#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    ll n;cin>>n;
    vector<ll> a(n+1);
    vector<P> v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v.push_back(P(a[i],i));
    }
    sort(v.rbegin(),v.rend());
    v.push_back(P(0,0));
    vector<ll> res(n+1,0);
    ll mi=v[0].second;
    for(int i=0;i<n;i++){
        mi=min(mi,v[i].second);
        res[mi] += (i+1)*(v[i].first-v[i+1].first);
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<endl;
}
