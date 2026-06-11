#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    string s, ans = "";
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'B') {
            if (ans.size() != 0) ans.pop_back();
        } else
            ans += s[i];
    }
    cout << ans << endl;
    return 0;
}