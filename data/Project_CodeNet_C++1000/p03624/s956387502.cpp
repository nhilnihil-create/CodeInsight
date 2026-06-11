#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string S;
    cin >> S;
    set<char> data;
    for (char s : S) {
        data.insert(s);
    }
    string ans = "None";
    rep (i, 26) {
        if (data.count('a' + i) == 0) {
            ans = 'a' + i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}