#include <bits/stdc++.h>
#include <complex>
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

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main() {
    cin>>N;
    vec a(N*3), left_sum(N+1,0), right_sum(N+1,0);
    multiset<ll> left,right;
    rep(i,N*3) cin>>a[i];
    rep(i,N) {
        left.insert(a[i]);
        left_sum[0] += a[i];
    }
    reps(i,N*2, N*3) {
        right.insert(a[i]);
        right_sum[N] += a[i];
    }
    reps(i,N,N*2){
        left.insert(a[i]);
        left_sum[i - (N - 1)] = left_sum[i - N] + a[i] - *left.begin();
        left.erase(left.begin());
    }
    for(ll i = N*2 - 1; i >= N; --i){
        right.insert(a[i]);
        right_sum[i - N] = right_sum[i - N + 1] + a[i] - *right.rbegin();
        right.erase(--right.end());
    }
    ll ans = -(1e+15);
    rep(i,N+1) ans = max(ans, left_sum[i] - right_sum[i]);
    cout<<ans<<endl;
}