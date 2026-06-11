#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> v;
    rep(i, 0, n) {
        if (s1[i] == s2[i]) v.push_back(1);
        else {
            v.push_back(2);
            i++;
        }
    }
    ll ans = 1;
    rep(i, 0, (int)v.size()) {
        if (i == 0) {
            if (v[i] == 1) ans *= 3;
            else ans *= 6;
            continue;
        }
        if (v[i] == 1) {
            if (v[i - 1] == 1) ans *= 2;
            ans %= MOD;
        } else {
            if (v[i - 1] == 1) ans *= 2;
            else ans *= 3;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
