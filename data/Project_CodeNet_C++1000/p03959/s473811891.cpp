#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAX_N = 1.0e5 + 100;
ll T[MAX_N], A[MAX_N];
const int MOD = 1.0e9 + 7;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> T[i];
    for (int i = 0; i < N; i++) cin >> A[i];

    ll m[N];
    memset(m, -1, sizeof(m));

    m[0] = T[0];
    for (int i = 1; i < N; i++) {
        if (T[i-1] < T[i]) {
            m[i] = T[i];
        }
    }

    bool possible = true;

    if (m[N-1] != -1 && m[N-1] != A[N-1]) {
        possible = false;
    }
    else {
        m[N-1] = A[N-1];
    }

    for (int i = N-2; i >= 0; i--) {
        if (m[i] != -1 && A[i] < m[i]) {
            possible = false;
        }
        if (A[i] > A[i+1]) {
            if (m[i] != -1 && m[i] != A[i]) {
                possible = false;
            }
            else {
                m[i] = A[i];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (m[i] == T[i]) {
            if (m[i] > A[i]) {
                possible = false;
            } 
        }
        else if (m[i] == A[i]) {
            if (m[i] > T[i]) {
                possible = false;
            }
        }
    }

    if (possible) {
        ll ans = 1;
        for (int i = 0; i < N; i++) {
            if (m[i] == -1) {
                ans = (ans * min(T[i], A[i]) ) % MOD;
            }
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
