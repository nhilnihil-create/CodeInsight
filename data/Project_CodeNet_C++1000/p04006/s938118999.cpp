#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, x; cin >> N >> x;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];
    
    vector<int> B = A;
    ll ans = 1LL << 60;
    REP(i, 0, N) {
        REP(j, 0, N) B[j] = min(B[j], A[(N - i + j) % N]);
        ans = min(ans, accumulate(ALL(B), 0LL) + (ll)i * x);
    }
    
    cout << ans << endl;
    return 0;
}