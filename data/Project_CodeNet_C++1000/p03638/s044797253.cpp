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
#define prt(v) cout<<v<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<62;
const ll MOD=1000000007;

ll N,Q,K;
vector<ll> a(100007,0);
vector<ll> b(100007,0);
vector<ll> c(100007,0);
vector<ll> x(100007,0);
vector<ll> y(100007,0);
vector<ll> d(100007,INF);
vector<vector<P>> G(100007, vector<P>(0));


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    ll N;
    cin >> N;
    vector<ll> a(N,0);
    for(ll i=0;i<N;++i)cin>>a[i];
    vector<vector<ll>> ans(H, vector<ll>(W, 0));
    vector<ll> wait(0);
    for(ll i=0;i<N;++i){
        for(ll j=0;j<a[i];++j)wait.emplace_back(i+1);
    }
    ll index=0;
    for(ll i=0;i<H;++i){
        if(i%2){
            for(ll j=0;j<W;++j){ans[i][j]=wait[index];index++;}
        }
        else {
            for(ll j=W-1;j>=0;--j){ans[i][j]=wait[index];index++;}
        }
    }
    for(ll i=0;i<H;++i){
        for(ll j=0;j<W;++j)cout<<ans[i][j]<<" ";cout<<endl;
    }

    
    return 0;
}
