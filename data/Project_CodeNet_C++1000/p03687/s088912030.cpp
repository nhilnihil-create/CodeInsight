#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(std::string s) {
    ll ans = 1000;
    rep(i, 26) {
        char c = 'a' + i;
        string tmps = s;
        ll cnt = 0;
        rep(k, tmps.size()) {
            if (tmps[k] == c) {
                cnt++;
            }
        }
        if (cnt == tmps.size()) {
            ans = min(ans, 0LL);
            continue;
        }

        rep(j, s.size() - 1) {
            rep(k, tmps.size()) {
                if (tmps[k] == c || tmps[k + 1] == c) {
                    tmps[k] = c;
                }
            }
            tmps.pop_back();
            ll cnt = 0;
            rep(k, tmps.size()) {
                if (tmps[k] == c) {
                    cnt++;
                }
            }
            if (cnt == tmps.size()) {
                ans = min(ans, j + 1);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::string s;
    std::cin >> s;
    solve(s);
    return 0;
}
