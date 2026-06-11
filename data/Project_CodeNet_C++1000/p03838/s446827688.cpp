#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    ll X, Y;
    cin >> X >> Y;
    vector<bool> s1 = {true, true, false, false};
    vector<bool> s2 = {true, false, true, false};
    priority_queue<ll, vector<ll>, greater<ll>> ans;
    rep(i, 4) {
        ll count = 0;
        ll x = X;
        ll y = Y;
        if (s1[i]) {
            count++;
            x = -X;
        }
        if (s2[i]) {
            count++;
            y = -Y;
        }
        if (x <= y) {
            count += y-x;
            ans.push(count);
        }
    }
    cout << ans.top() << endl;
}