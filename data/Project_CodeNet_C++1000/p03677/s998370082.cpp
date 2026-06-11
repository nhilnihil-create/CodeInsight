#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define exists(s,x) (s).find(x)!=(s).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
#define fi first
#define se second
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}
inline ll modpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y&1) res = mul(res,x);
        y >>= 1;
        x = mul(x,x);
    }
    return res;
}

int main(){
    int N, M; cin >> N >> M;
    vector<int> A(N);
    ll ans = 0;
    REP(i,N) {
        cin >> A[i]; A[i]--;
    }
    REP(i,N-1) {
        if(A[i+1]>A[i])ans += (ll)A[i+1] - A[i];
        else ans += (ll)A[i+1]- A[i] + M;
    }
    vector<ll> v(2*M+1);
    REP(i,N-1) {
        if(A[i+1]>A[i]){
            v[A[i]+2]++;
            v[A[i+1]+1]--;
        }
        else {
            v[A[i]+2]++;
            v[A[i+1]+M+1]--;
        }
    }
    REP(i,2*M) v[i+1] += v[i];
    // REP(i,2*M+1) cout << v[i] << " "; cout << endl;
    REP(i,N-1) {
        if(A[i+1]>A[i]) v[A[i+1]+1] -= A[i+1] - A[i] - 1;
        else v[A[i+1]+1+M] -= A[i+1] + M - A[i] - 1;
    }
    REP(i,2*M) v[i+1] += v[i];
    // REP(i,2*M+1) cout << v[i] << " "; cout << endl;
    ll ma = 0;
	REP(i,M) ma = max(ma, v[i] + v[i+M]);
    ans -= ma;
    cout << ans << endl;
    return 0;
}