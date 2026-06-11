#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    rep(i, N) cin >> A.at(i);
    rep(i, M) cin >> B.at(i);

    bool exist = false;
    rep(i, N - M + 1) {      // 縦方向の正方形の移動
        rep(j, N - M + 1) {  // 横方向の正方形の移動
            bool isSame = true;
            rep(k, M) {      // 縦方向の正方形の要素
                rep(l, M) {  // 横方向の正方形の要素
                    if (A.at(i + k).at(j + l) != B.at(k).at(l)) isSame = false;
                }
            }
            if (isSame) exist = true;
        }
    }

    string ans = exist ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}