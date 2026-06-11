#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

int main() {
    int A, B, C;
    string ans = "NO";

    cin >> A >> B >> C;

    rep(b, B) {
        if ((A*b)%B == C) {
            ans = "YES";
            break;
        }
    }

    cout << ans << endl;
}
