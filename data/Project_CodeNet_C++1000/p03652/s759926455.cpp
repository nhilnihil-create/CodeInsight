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
    cin>>N>>M;
    mat a(N, vec(M));
    rep(i,N) rep(j,M) cin>>a[i][j], --a[i][j];
    vector<bool> stop(M, false);
    vec id(N,0), memo(M, 0);
    ll ans = N;
    rep(roop,M){
        rep(i,N){
            while(stop[a[i][id[i]]]) ++id[i];
            ++memo[a[i][id[i]]];
        }
        auto ite = max_element(ALL(memo));
        ans = min(ans, *ite);
        stop[ite - memo.begin()] = true;
        rep(i,M) memo[i] = 0;
    }
    cout<<ans<<endl;
}