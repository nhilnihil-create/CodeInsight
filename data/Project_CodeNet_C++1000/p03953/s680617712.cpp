#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define int long long
#define INF 1000000000000000000
using namespace std;

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
template<typename T>
void debug(vector<vector<T>> m){ REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;} }



signed main(){

    int N; cin >> N;
    vec x(N); readv(x);
    int M, K; cin >> M >> K;
    vec a(M); readv(a);

    vec d(N - 1);
    REP(i, N - 1) d[i] = x[i + 1] - x[i];

    mat next(61, vec(N - 1));
    REP(i, N - 1) next[0][i] = i;
    REP(i, M) swap(next[0][a[i] - 2], next[0][a[i] - 1]);
    FOR(i, 1, 61) REP(j, N - 1) next[i][j] = next[i - 1][next[i - 1][j]];

    int A = x[0];
    cout << A << endl;
    REP(i, N - 1){
        int u = i;
        IREP(j, 61) if((K >> j) & 1) u = next[j][u];
        A += d[u];
        cout << A << endl;
    }

    return 0;
}
