#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll w, h;
ll ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    cin >> w >> h;
    rep(i, 0, w) {
        ll p;
        cin >> p;
        q.push({p, 0});
    }

    rep(i, 0, h) {
        ll p;
        cin >> p;
        q.push({p, 1});
    }
    ++w, ++h;
    // 0 - col, 1 - row
    ll cols = 0, rows = 0;
    while (!q.empty()) {
        pair<ll, ll> v = q.top();
        q.pop();
        if (v.second == 0) {
            ans += (h - rows) * v.first;
            // cout << h - rows << ' ' << v.first << endl;
            ++cols;
        } else {
            ans += (w - cols) * v.first;
            // cout << w - cols << ' ' << v.first << endl;
            ++rows;
        }
    }
    cout << ans;
}
