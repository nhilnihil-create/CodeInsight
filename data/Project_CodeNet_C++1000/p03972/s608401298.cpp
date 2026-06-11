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
    ll rest_w = w, rest_h = h;
    for (int c = 0; c < h + w; ++c) {
        if (p.empty()) {
            ll top = q.top();
            q.pop();
            ans += top * (rest_w + 1);
            --rest_h;
        } else if (q.empty()) {
            ll top = p.top();
            p.pop();
            ans += top * (rest_h + 1);
            --rest_w;
        } else {
            ll pt = p.top();
            ll qt = q.top();
            if (pt < qt) {
                p.pop();
                ans += pt * (rest_h + 1);
                --rest_w;
            } else {
                q.pop();
                ans += qt * (rest_w + 1);
                --rest_h;
            }
        }
    }
    cout << ans;
    return 0;
}
