#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int w, h; cin >> w >> h;
    priority_queue<ll, vector<ll>, greater<ll>> p, q;
    for (int i = 0; i < w; ++i) {
        ll pi; cin >> pi;
        p.push(pi);
    }
    for (int i = 0; i < h; ++i) {
        ll qi; cin >> qi;
        q.push(qi);
    }
    ll ans = 0;
    for (int c = 0; c < h + w; ++c) {
        if (q.empty() || (!p.empty() && p.top() < q.top())) {
            ans += p.top() * (q.size() + 1);
            p.pop();
        } else {
            ans += q.top() * (p.size() + 1);
            q.pop();
        }
    }
    cout << ans;
    return 0;
}
