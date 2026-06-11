#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    bool isYes = false;
    rep(i, B) {
        if (((i + 1) * A) % B == C)
            isYes = true;
    }

    string ans = isYes ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}