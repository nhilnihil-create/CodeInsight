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

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



signed main(){

    int N, T; cin >> N >> T;
    vec A(N); readv(A);

    vec maxA(N);
    maxA[N - 1] = A[N - 1];
    IREP(i, N - 1) maxA[i] = max(A[i], maxA[i + 1]);

    int m = -1;
    REP(i, N) m = max(m, maxA[i] - A[i]);
    int ans = 0;
    REP(i, N) if(maxA[i] - A[i] == m) ans++;
    cout << ans;
    
    return 0;
}