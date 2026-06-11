#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int tol = 0;
    if (N > K) {
        rep (i, K) {
            tol += 1 * X;
        }
        rep(i, N-K) {
            tol += 1 * Y;
        }
    } else {
        rep(i, N) {
            tol += 1 * X;
        }
    }
    
    cout << tol << endl;

    return 0;
}