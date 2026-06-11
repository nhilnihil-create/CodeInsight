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

vector<vector<ll>> G(100007, vector<ll>(0));

void dfs(ll x,vl &d){
    for(auto p: G[x]){
        if(d[p]==-1){
            d[p]=d[x]+1;
            dfs(p,d);
        }
    }
}


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<char> A(N);
    vector<char> B(N);
    for(ll i=0;i<N;++i)cin>>A[i];
    for(ll i=0;i<N;++i)cin>>B[i];
    vector<ll> vec(0);
    for(ll i=0;i<N;++i){
        if(A[i]==B[i])vec.emplace_back(1);
        else {
            vec.emplace_back(2);
            i++;
        }
    }
    ll ans;
    if(vec[0]==1)ans=3;
    else ans=6;
    for(ll i=1;i<vec.size();++i){
        ll &a=vec[i-1],&b=vec[i];
        if(a==1&&b==1)ans*=2;
        else if(a==1&&b==2)ans*=2;
        else if(a==2&&b==1)ans*=1;
        else if(a==2&&b==2)ans*=3;
        ans%=MOD;
    }
    prt(ans)
    return 0;
}
