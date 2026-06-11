#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
// const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    bool ok = true;
    vector<int> cnt(N);
    rep(i,N) cnt[A[i]]++;
    int M = *max_element(all(A));
    if (M%2==0) {
        if (cnt[M/2] != 1) ok = false;
        for (int i = M; i > M/2; i--) {
            if (cnt[i] < 2) ok = false;
        }
    } else {
        if (cnt[(M+1)/2] != 2) ok = false;
        for (int i = M; i > (M+1)/2; i--) {
            if (cnt[i] < 2) ok = false;
        }
    }

    cout << (ok ? "Possible" : "Impossible") << endl;
}