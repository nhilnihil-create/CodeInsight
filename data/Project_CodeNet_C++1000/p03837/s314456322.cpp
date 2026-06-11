#include <bits/stdc++.h>
#include <bitset>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>M;
    mat G(N, vec(N, INF));
    vec a(M), b(M), c(M);
    rep(i,M){
        cin>>A>>B>>c[i];
        --A, --B;
        G[A][B] = G[B][A] = c[i];
        a[i] = A;
        b[i] = B;
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    ll ans = 0;
    rep(i,M){
        ans += G[a[i]][b[i]] < c[i];
    }
    cout<<ans<<endl;
}