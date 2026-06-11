#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int direct(int x, int y) {
    if (x == y) return 0;
    if (x > y) return 1;
    return 2;
}

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int ans = 1, i = 0;
    while (i < N - 1) {
        if (A[i] == A[i + 1]) {
            ++i;
            continue;
        }
        int group = direct(A[i], A[i + 1]);
        int j = i;
        for (; j < N - 1; ++j) {
            if (A[j] == A[j + 1]) continue;
            if (group != direct(A[j], A[j + 1])) {
                ans += 1;
                break;
            }
        }
        i = j + 1;
    }
    cout << ans << endl;
}
