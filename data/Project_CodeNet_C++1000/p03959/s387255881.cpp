#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    vector<int> lower(N, INT32_MAX);
    vector<bool> confirm(N, false);

    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] > A[i-1]) {
            confirm[i] = true;
        }
        lower[i] = A[i];
    }

    for (int i = N-1; i >= 0; i--) {
        if (i == N-1 || B[i] > B[i+1]) {
            if (confirm[i]) {
                if (lower[i] != B[i]) {
                    cout << 0 << endl;
                    return 0;
                }
            } else {
                if (B[i] > lower[i]) {
                    cout << 0 << endl;
                    return 0;
                }
                confirm[i] = true;
                lower[i] = B[i];
            }
        } else {
            lower[i] = min(lower[i], B[i]);
        }
    }

    long long MOD = 1e9 + 7;
    long long ret= 1;
    for (int i= 0; i < N; i++) {
        if (confirm[i]) continue;
        (ret *= lower[i]) %= MOD;
    }
    cout << ret << endl;
}