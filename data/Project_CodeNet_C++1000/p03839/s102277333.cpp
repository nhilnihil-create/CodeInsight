#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>K;
    vec a(N);
    rep(i,N) cin>>a[i];
    ll sum, plus, minus;
    sum = plus = minus = 0;
    rep(i,N) sum += max(0LL, a[i]);
    ll ans = 0;
    rep(i,K){
        (a[i] >= 0 ? plus : minus) += abs(a[i]);
    }
    ans = max({ans, sum - plus, sum - minus});
    reps(i,K,N){
        (a[i-K] >= 0 ? plus : minus) -= abs(a[i-K]);
        (a[i] >= 0 ? plus : minus) += abs(a[i]);
        ans = max({ans, sum - plus, sum - minus});
        //if(i == N - 1) cout<<sum<<' '<<plus<<' '<<minus<<endl;
    }
    cout<<ans<<endl;
}