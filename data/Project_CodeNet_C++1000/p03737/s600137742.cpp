#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string ans;
    vec<string> s(3);
    rep(i, 3) {
        cin >> s[i];
        ans += toupper(s[i][0]);
    }

    cout << ans << endl;
}
