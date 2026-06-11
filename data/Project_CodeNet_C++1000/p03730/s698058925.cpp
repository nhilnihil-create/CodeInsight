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
    rep(i, 1000) { // O(10^8)
        rep(j, 1000) {
            if ((A * i) - (B * j) == C)
                isYes = true;
        }
    }

    string ans = isYes ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}