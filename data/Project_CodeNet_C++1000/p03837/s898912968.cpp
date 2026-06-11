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
    ll M;
    cin >> M;
    vector<ll> a(M,0);
    vector<ll> b(M,0);
    vector<ll> c(M,0);
    for(ll i=0;i<M;++i){cin>>a[i]>>b[i]>>c[i];a[i]--;b[i]--;}
    vector<vector<ll>> d(N, vector<ll>(N, INF));
    for(ll i=0;i<N;++i)d[i][i]=0;
    for(ll i=0;i<M;++i){
        d[a[i]][b[i]]=c[i];
        d[b[i]][a[i]]=c[i];
    }

    //ワーシャルフロイド法
    for(ll i=0;i<N;++i)
            for(ll j=0;j<N;++j)
                for(ll k=0;k<N;++k)chmin(d[j][k],d[j][i]+d[i][k]);
    
    ll ans=0;
    for(ll i=0;i<M;++i)if(d[a[i]][b[i]]<c[i])ans++;
    prt(ans)

    return 0;
}
