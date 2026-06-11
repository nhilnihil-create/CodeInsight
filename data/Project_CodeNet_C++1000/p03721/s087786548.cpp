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
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;



signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    deque<P> vec;
    for(ll i=0;i<N;++i){
        ll a;
        cin >> a;
        ll b;
        cin >> b;
        vec.emplace_back(P(a,b));
    }
    sort(vec.begin(), vec.end());
    ll num=0;ll ans=0;
    while(num<K){
        num+=vec[0].second;
        ans=vec[0].first;
        vec.pop_front();
    }
    prt(ans)fl


    return 0;
}
