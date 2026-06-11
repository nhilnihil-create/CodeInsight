// Ti と Ai の記録から、各山の高さの上界がわかる
// T(i-1) < Ti のとき、i番目の山がSiなのが確定
// Ai > A(i-1) のとき、i番目の山がAiなのは確定
// 確定させたとき、両者の値が違う、若しくは、
// Tiで山の高さが確定したとき、Ti > Ai
// Aiで山の高さが確定したとき、Ai > Ti
// となる場合、矛盾が生じるので答えはない
// それ以外の値については1 ～ min(Ai, Ti)だけ山の高さがあり得そう
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    int N;
    cin >> N;
    vector<int> T(N + 2, 0), A(N + 2, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> T[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<int> S(N + 2, 0);
    for (int i = 1; i <= N; ++i) {
        if (T[i - 1] < T[i]) {
            S[i] = T[i];
        }
    }
    for (int i = N; i >= 1; --i) {
        if (A[i] > A[i + 1]) {
            if (S[i] != 0 && A[i] != S[i]) {
                cout << 0 << endl;
                return 0;
            }
            // S[i] == 0のとき
            if (A[i] > T[i]) {
                cout << 0 << endl;
                return 0;
            }
            S[i] = A[i];
        }
    }

    long long res = 1;
    for (int i = 1; i <= N; ++i) {
        if (S[i] != 0) {
            continue;
        }
        res = res * min(A[i], T[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}