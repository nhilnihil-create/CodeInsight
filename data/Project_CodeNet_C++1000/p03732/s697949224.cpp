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
    ll W;
    cin >> W;
    vector<ll> w(N,0);
    vector<ll> v(N,0);
    for(ll i=0;i<N;++i)cin>>w[i]>>v[i];
    vector<ll> a(0);
    vector<ll> b(0);
    vector<ll> c(0);
    vector<ll> d(0);
    for(ll i=0;i<N;++i){
        if(w[i]==w[0])a.emplace_back(v[i]);
        else if(w[i]==w[0]+1)b.emplace_back(v[i]);
        else if(w[i]==w[0]+2)c.emplace_back(v[i]);
        else if(w[i]==w[0]+3)d.emplace_back(v[i]);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    sort(d.rbegin(), d.rend());
    ll A=a.size(),B=b.size(),C=c.size(),D=d.size();
    vector<ll> sua(A+1,0);
    vector<ll> sub(B+1,0);
    vector<ll> suc(C+1,0);
    vector<ll> sud(D+1,0);
    for(ll i=1;i<=A;++i)sua[i]=sua[i-1]+a[i-1];
    for(ll i=1;i<=B;++i)sub[i]=sub[i-1]+b[i-1];
    for(ll i=1;i<=C;++i)suc[i]=suc[i-1]+c[i-1];
    for(ll i=1;i<=D;++i)sud[i]=sud[i-1]+d[i-1];

    ll ans=0;
    for(ll i=0;i<=N&&i<=A;++i){
        for(ll j=0;j<=N-i&&j<=B;++j){
            for(ll k=0;k<=N-i-j&&k<=C;++k){
                for(ll l=0;l<=N-i-j-k&&l<=D;++l){
                    if(w[0]*i+(w[0]+1)*j+(w[0]+2)*k+(w[0]+3)*l>W)continue;
                    chmax(ans,sua[i]+sub[j]+suc[k]+sud[l]);
                }
            }
        }
    }
    prt(ans)

    return 0;
}
