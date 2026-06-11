#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int slen = s.length();
    pii ans = {-1, -1};
    for (int i = 0; i < slen; ++i) {
        if (i + 1 < slen && s[i] == s[i + 1]) {
            ans.first = i + 1;
            ans.second = i + 2;
            break;
        }
        if (i + 2 < slen && s[i] == s[i + 2]) {
            ans.first = i + 1;
            ans.second = i + 3;
            break;
        }
    }

    cout << ans.first << " " << ans.second << endl;

    return 0;
}
