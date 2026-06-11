#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;

    ll ans = 2 * n;
    rep(i, n) {
        // cout << s.substr(i) << ' ' << t.substr(0, n - i) << endl;
        if(s.substr(i) == t.substr(0, n - i)) {
            // cout << n + i << endl;
            ans = min(ans, n + i);
        }
    }
    cout << ans << endl;
}
