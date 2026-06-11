#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll a, b;
int main() {
    cin >> a >> b;
    if (a == 0 || b == 0) {
        cout << "Zero" << endl;
        return 0;
    }

    // 0 をまたぐので 0
    if (a < 0 && b > 0 || a > 0 && b < 0) {
        cout << "Zero" << endl;
        return 0;
    }

    // 両方マイナス
    if (a < 0 && b < 0) {
        // 個数
        ll target = -b - (- a) + 1;
        if (target % 2 == 0) {
            cout << "Positive" << endl;
        } else {
            cout << "Negative" << endl;
        }
    } else {
        // 両方プラス
        cout << "Positive" << endl;
    }
}