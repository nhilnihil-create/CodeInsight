#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;

    vec<string> A(N);
    rep(i, N) cin >> A[i];

    vec<string> B(M);
    rep(i, M) cin >> B[i];

    rep(i, N - M + 1) rep(j, N - M + 1) {
        bool flag = true;
        rep(k, M) {
            rep(l, M) {
                if (A[i + k][j + l] != B[k][l]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) { cout << "Yes" << '\n';return 0; }
    }
    cout << "No" << '\n';
}
