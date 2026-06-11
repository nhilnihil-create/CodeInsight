#include <bits/stdc++.h>
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

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    ll X;
    cin>>N>>X;
    mat buy(N, vec(N));
    rep(i,N) cin>>buy[0][i];
    reps(i,1,N){
        ll last = buy[i-1][N-1];
        rep(j,N){
            buy[i][j] = min(buy[i-1][j], last);
            last = buy[i-1][j];
        }
    }
    ll ans = INF;
    rep(i,N){
        ll sum = 0;
        rep(j,N) sum += buy[i][j];
        ans = min(ans, sum + X * i);
    }
    cout<<ans<<endl;
}