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
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(3*N,0);
    for(ll i=0;i<3*N;++i)cin>>a[i];
    //b[i]は区間[0,N+i)の上位N個のsum
    vector<ll> b(N+1,0);
    //c[i]は区間[N+i,3N)の下位N個のsum
    vector<ll> c(N+1,0);
    ll sum=0;
    multiset<ll> S;
    for(ll i=0;i<N;++i){S.insert(a[i]);sum+=a[i];}
    for(ll i=0;i<=N;++i){
        b[i]=sum;
        S.insert(a[N+i]);
        sum+=a[N+i];
        sum-=(*S.begin());
        S.erase(S.begin());
    }

    S.clear();
    sum=0;

    for(ll i=2*N;i<3*N;++i){S.insert(a[i]);sum+=a[i];}
    for(ll i=N;i>=0;--i){
        c[i]=sum;
        S.insert(a[N+i-1]);
        sum+=a[N+i-1];
        sum-=(*(prev(S.end())));
        S.erase((prev(S.end())));
    }

    ll ans=-INF;
    for(ll i=0;i<=N;++i)chmax(ans,b[i]-c[i]);

    prt(ans)

    return 0;
}
