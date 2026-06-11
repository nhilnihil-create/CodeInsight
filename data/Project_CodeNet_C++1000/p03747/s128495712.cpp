#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



signed main(){

    int N, L, T; cin >> N >> L >> T;
    vec X(N), W(N);
    REP(i, N) cin >> X[i] >> W[i];
    vec Y(N);
    REP(i, N){
        if(W[i] == 1) Y[i] = (X[i] + T) % L;
        else Y[i] = ((X[i] - T) % L + L) % L;
    }
    int p0 = Y[0];
    SORT(Y);

    //0が衝突する回数 
    int n0 = 0;
    REP(i, N){
        if(W[i] == W[0]) continue;
        if(W[0] == 1) n0 += (2 * T - (X[i] - X[0]) - 1 + L) / L;
        else n0 += (2 * T - (X[0] + L - X[i]) + L) / L;
    }
    //cout << n0 << endl;
    if(W[0] == 2) n0 = (N - (n0 % N)) % N;
    int i0 = Lower_bound(Y, p0);
    vec ans(N);
    REP(i, N) ans[(n0 + i) % N] = Y[(i0 + i) % N];

    REP(i, N) cout << ans[i] << endl;
    
    return 0;
}