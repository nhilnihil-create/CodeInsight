#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n,0);
    for(ll i=0;i<n;++i)cin>>A[i];
    deque<ll> ans;
    for(ll i=0;i<n;++i){
        if(i%2)ans.emplace_back(A[i]);
        else ans.emplace_front(A[i]);
    }
    if(n%2==0)reverse(ans.begin(), ans.end());
    for(ll i=0;i<n;++i)cout<<ans[i]<<" ";cout<<endl;fl

    return 0;
}
