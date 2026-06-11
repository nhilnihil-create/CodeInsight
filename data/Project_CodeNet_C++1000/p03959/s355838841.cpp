#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N;
ll T[100010], A[100010];
ll P[100010], Q[100010], R[100010], S[100010];

signed main(){
    cin >> N;
    REP(i, N) cin >> T[i];
    REP(i, N) cin >> A[i];
    ll m = 0;
    REP(i, N){
        if(m < T[i]){
            P[i] = Q[i] = T[i];
            m = T[i];
        }else{
            P[i] = 1; Q[i] = m; 
        }
    }
    m = 0;
    for(int i = N - 1; i >= 0; i--){
        if(m < A[i]){
            R[i] = S[i] = A[i];
            m = A[i];
        }else{
            R[i] = 1; S[i] = m;
        }
    }
    ll ans = 1;
    REP(i, N){
        ans *= max(0LL, min(Q[i], S[i]) - max(P[i], R[i]) + 1);
        ans %= MOD;
    }
    PRINT(ans);
    return 0;
}