#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> D(K);
    rep(i, K) cin >> D.at(i);

    string ans;
    for (int i = N; i < 1000000; i++) { // 100000 * 5 * 10 -> OK
        string digits = to_string(i);
        bool isOk = true;
        for (char digit : digits) {
            rep(j,K) {
                if (digit - '0' == D.at(j)) isOk = false;
            }
        }
        if (isOk) {
            ans = digits;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
