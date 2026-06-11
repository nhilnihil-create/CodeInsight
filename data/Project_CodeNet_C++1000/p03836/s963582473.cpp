#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
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
    ll sx;
    cin >> sx;
    ll sy;
    cin >> sy;
    ll tx;
    cin >> tx;
    ll ty;
    cin >> ty;
    ll A=tx-sx;
    ll B=ty-sy;
    deque<char> ans;
    for(ll i=0;i<B;++i)ans.emplace_back('U');
    for(ll i=0;i<A;++i)ans.emplace_back('R');
    ans.emplace_back('U');
    for(ll i=0;i<A+1;++i)ans.emplace_back('L');
    for(ll i=0;i<B+1;++i)ans.emplace_back('D');
    ans.emplace_back('R');
    ans.emplace_back('D');
    for(ll i=0;i<A+1;++i)ans.emplace_back('R');
    for(ll i=0;i<B+1;++i)ans.emplace_back('U');
    ans.emplace_back('L');
    for(ll i=0;i<B;++i)ans.emplace_back('D');
    for(ll i=0;i<A;++i)ans.emplace_back('L');
    for(ll i=0;i<ans.size();++i)cout<<ans[i];
    cout<<endl;


    return 0;
}
