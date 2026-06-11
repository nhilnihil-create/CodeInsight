#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second > b.second; }

signed main() {
    string s;cin>>s;ll n=s.size();

    vl abc(26);
    rep(i,n)abc[s[i]-'a']++;

    ll ans=n*(n-1)/2; //n文字の組み合わせの総和から
    rep(i,26)ans -= abc[i] * (abc[i]-1) / 2; //同じ文字の組み合わせ総和を引く
    cout<<ans+1<<endl;
}