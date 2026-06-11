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
    cin>>N;
    vec x(N);
    rep(i,N) cin>>x[i];
    vec memo(N,0);
    reps(i,1,N){
        memo[i] = max({i - (x[i] - 1)/2, memo[i-1], 0LL});
    }
    ll ans = 1, id = 0, num = 1;
    rep(i,N){
        //cout<<i<<' '<<memo[i]<<endl;
        while(memo[id] <= i && id != N - 1) {
            ++id;
            ++num;
        }
        //cout<<num<<endl;
        (ans *= num)%=MOD;
        --num;
    }
    cout<<ans<<endl;
}