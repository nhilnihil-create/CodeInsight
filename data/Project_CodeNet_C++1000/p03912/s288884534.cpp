#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M), P(M);
    vector<set<int>> S(M);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[x % M]++;
        if (S[x % M].count(x)) {
            P[x % M]++;
            S[x % M].erase(x);
        } else {
            S[x % M].insert(x);
        }
    }
    int ans = 0;
    for (int i = 0; i <= M / 2; i++) {
        if (i == 0 || i * 2 == M) {
            ans += A[i] / 2;
        } else {
            if (A[i] > A[M - i]) {
                ans += A[M - i] + min(P[i], (A[i] - A[M - i]) / 2);
            } else {
                ans += A[i] + min(P[M - i], (A[M - i] - A[i]) / 2);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
