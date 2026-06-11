#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    vector<string> B(m);
    rep(i, n) cin >> A.at(i);
    rep(i, m) cin >> B.at(i);

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            bool is_in = true;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (A[i + k][j + l] != B[k][l]) {
                        is_in = false;
                    }
                }
            }

            if (is_in) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}