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
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(M, vector<char>(M));
    for(ll i=0;i<N;++i)
        for(ll j=0;j<N;++j)cin>>A[i][j];
    for(ll i=0;i<M;++i)
        for(ll j=0;j<M;++j)cin>>B[i][j];
    for(ll i=0;i<N-M+1;++i){
        for(ll j=0;j<N-M+1;++j){
            bool ok=1;
            for(ll k=0;k<M;++k){
                for(ll l=0;l<M;++l){
                    if(A[k+i][l+j]!=B[k][l]){
                        ok=0;break;
                    }
                }
            }
            if(ok){prt("Yes")return 0;}
        }
    }
    prt("No")

    return 0;
}
