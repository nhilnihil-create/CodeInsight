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
    ll N;
    cin >> N;
    ll x;
    cin >> x;
    vector<ll> A(N,0);
    for(ll i=0;i<N;++i)cin>>A[i];
    ll ans=0;
    if(A[0]>x){
        ans+=A[0]-x;
        A[0]=x;
    }
    for(ll i=1;i<N;++i){
        if(A[i-1]+A[i]<=x)continue;
        ans+=A[i-1]+A[i]-x;
        A[i]=x-A[i-1];
    }
    prt(ans)
    return 0;
}
