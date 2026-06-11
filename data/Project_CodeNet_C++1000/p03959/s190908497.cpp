#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define MOD 1000000007

using namespace std;

using ll = long long;

ll solve() {
    int N;
    cin >> N;
    vector<int> T(N + 2), A(N + 2);
    T[0] = 0;
    T[N + 1] = T[N];
    A[0] = 0;
    A[N + 1] = A[N];
    FOR(i, 1, N + 1) cin >> T[i];
    FOR(i, 1, N + 1) cin >> A[i];

    ll result = 1;
    FOR(i, 1, N + 1) {
        if (T[i - 1] < T[i] && A[i] > A[i + 1]) {
            if (T[i] != A[i]) {
                return 0;
            }
        } else if (T[i - 1] < T[i]) {
            if (T[i] > A[i]) {
                return 0;
            }
        } else if (A[i] > A[i + 1]) {
            if (A[i] > T[i]) {
                return 0;
            }
        } else {
            result = (result * min(T[i], A[i])) % MOD;
        }
    }
    return result;
}

int main() {
    cout << solve() << endl;
    return 0;
}