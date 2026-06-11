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
    ll N,A,B,a,b;
    cin>>N;
    a=b=1;
    rep(i,N){
        cin>>A>>B;
        ll k=max((a-1)/A,(b-1)/B)+1;
        debug(k)
        a=k*A;
        b=k*B;
    }
    cout<<a+b<<endl;
}