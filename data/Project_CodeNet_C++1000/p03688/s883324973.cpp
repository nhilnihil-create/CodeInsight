#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

bool solve() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end());
    int dif = A[N-1] - A[0];
    if(dif == 0) {
        return A[0] == N - 1 || 2 * A[0] <= N;
    } else if(dif == 1) {
        int x = 0;
        rep(i, 0, N) if(A[i] == A[0]) x++;
        int y = A[N-1] - x;
        return x < A[N-1] && x + 2 * y <= N;
    }
    return false;
}

int main() {
    cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}
