#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    string ans;
    for (int i = 0; i < s.size(); i += 2) {
        ans += s.at(i);
    }

    cout << ans << endl;

    return 0;
}