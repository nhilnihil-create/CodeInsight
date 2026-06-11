#pragma GCC optimize("O3")
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
#define endl '\n'
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
    vector<ll> T(N+2,0);
    vector<ll> A(N+2,0);
    for(ll i=0;i<N;++i)cin>>T[i+1];
    for(ll i=0;i<N;++i)cin>>A[i+1];
    T[N+1]=T[N];
    A[0]=A[1];
    ll ans=1;
    //T[i]T[i+1]A[i+1]A[i+2]を比較
    for(ll i=0;i<N;++i){
        if(T[i]==T[i+1]){
            if(A[i+1]==A[i+2]){
                ans*=min(T[i+1],A[i+1]);
            }
            else{
                if(A[i+1]>T[i+1])ans*=0;
                else ans*=1;
            }
        }
        else{
            if(A[i+1]==A[i+2]){
                if(T[i+1]>A[i+1])ans*=0;
                else ans*=1;
            }
            else{
                if(T[i+1]==A[i+1])ans*=1;
                else ans*=0;
            }
        }
        ans%=MOD;
    }
    prt(ans)fl



    return 0;
}
