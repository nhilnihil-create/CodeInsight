#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;
const int MOD = 1000000007;
signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    int T[N],A[N];
    bool flag[N] = {};
    int maxv = 0;
    REP(i,N){
        cin >> T[i]; 
        maxv = max(maxv,T[i]);
        if(i != 0 && T[i-1] != T[i]){
            flag[i] |= 1;
        }
    }
    REP(i,N){
        cin >> A[i];
        if(flag[i] && T[i] > A[i]){
            cout << 0 << endl;
            return 0;
        }
        if(i != 0 && A[i-1] != A[i]){
            flag[i-1] |= 1;
            if(T[i-1] < A[i-1]){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    flag[0] = 1;flag[N-1] = 1;
    if(T[0] > A[0] || A[N-1] > T[N-1]){
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    REP(i,N){
        if(flag[i]) continue;
        ans *= min(T[i],A[i]);
        ans %= MOD;
    }
    bool F = 0;
    REP(i,N){
        if(A[i] == T[i] && T[i] == maxv) F = 1;
    }
    if(!F){
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;
}