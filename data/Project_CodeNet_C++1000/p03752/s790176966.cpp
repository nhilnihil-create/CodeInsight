#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N), M(N);
    REP(i, 0, N) cin >> A[i];

    M[0] = A[0];
    REP(i, 1, N) M[i] = max(M[i - 1], A[i]);

    ll ans = 1LL << 60;
    for (int bit = 0; bit < (1 << N); bit++) {

        int count = 1; ll prev = A[0], increase = 0;
        REP(i, 1, N) {
            int a = A[i]; ll prevMax = max(prev, (ll)M[i - 1]);
            if (bit & (1 << i)) {
                if (a <= prevMax) {
                    increase += prevMax - a + 1;
                    a = prevMax + 1;
                }
                count++;
                prev = a;
            }
        }
        if (count >= K) {
            // cout << "bit : " << bit << ", increase : " << increase << endl;
            ans = min(ans, increase);
        }
    }
    cout << ans << endl;
    
    return 0;
}