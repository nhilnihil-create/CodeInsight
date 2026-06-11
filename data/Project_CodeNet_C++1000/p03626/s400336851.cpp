#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    int n;
    vector<string> s(2);
    cin >> n >> s[0] >> s[1];

    vector<int> narabi;

    for (int i = 0; i < n;) {
        if (s[0][i] == s[1][i]) {
            narabi.push_back(0);
            i++;
        } else {
            narabi.push_back(1);
            i += 2;
        }
    }

    ll ans = 3;
    if (narabi[0] == 1) ans = 6;
    for (int i = 1; i < narabi.size(); ++i) {
        if (narabi[i] == 0) {
            if (narabi[i - 1] == 0) {
                ans *= 2;
            } else {
                ans *= 1;
            }
        } else {
            if (narabi[i - 1] == 0) {
                ans *= 2;
            } else {
                ans *= 3;
            }
        }
        ans %= MOD;
    }
    cout << ans << endl;
}