#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<ull> A(N), S(N + 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    S[0] = 0;
    for (int i = 0; i < N; ++i) S[i + 1] = S[i] + A[i];

    ull ans = 0;
    for (int i = 1; i < N; ++i) {
        // cout << A[i] << ' ' << S[i] << endl;

        // 色iが残るか
        if (A[i] <= 2 * S[i]) ++ans;
        else ans = 0;
    }
    ++ans;
    cout << ans << endl;
}
