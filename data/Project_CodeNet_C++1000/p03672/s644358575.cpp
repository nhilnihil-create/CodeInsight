#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string S;
    cin >> S;

    int ans = 2;
    while (S.size() > 2) {
        S = S.substr(0, S.size() - 1);
        if (S.size() % 2 == 0) {  // 文字列が偶数個
            string prevS = S.substr(0, S.size() / 2);
            string latterS = S.substr(S.size() / 2, S.size() / 2);
            if (prevS == latterS) {  // 偶文字列の場合
                ans = S.size();
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}