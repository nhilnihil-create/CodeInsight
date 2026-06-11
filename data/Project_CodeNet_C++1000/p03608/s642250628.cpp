#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using P = pair<ld,ld>;
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
const ll MOD=998244353;

ll N,M,R;
vector<vector<ll>> d(205, vector<ll>(205, INF));
vector<ll> r(8,0);


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    cin >> N;
    cin >> M;
    cin >> R;
    for(ll i=0;i<R;++i){cin>>r[i];r[i]--;}
    vector<ll> A(M,0);
    vector<ll> B(M,0);
    vector<ll> C(M,0);
    for(ll i=0;i<M;++i){cin>>A[i]>>B[i]>>C[i];A[i]--;B[i]--;}

    //ワーシャルフロイド法
    for(ll i=0;i<M;++i){
        d[A[i]][B[i]]=C[i];d[B[i]][A[i]]=C[i];
    }
    for(ll i=0;i<N;++i)d[i][i]=0;
    for(ll i=0;i<N;++i)
            for(ll j=0;j<N;++j)
                for(ll k=0;k<N;++k)chmin(d[j][k],d[j][i]+d[i][k]);
    vector<ll> zyun(R,0);
    iota(zyun.begin(), zyun.end(), 0);
    ll ans=INF;
    do{
        ll sum=0;
        for(ll i=0;i<R-1;++i){
            sum+=d[r[zyun[i]]][r[zyun[i+1]]];
        }
        chmin(ans,sum);
    }while(next_permutation(zyun.begin(), zyun.end()));
    prt(ans)

    


    return 0;
}
