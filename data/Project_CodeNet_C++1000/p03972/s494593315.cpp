#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int w, h; cin >> w >> h;
    priority_queue<int, vector<int>, greater<int>> p, q;
    for (int i = 0; i < w; ++i) {
        int pi; cin >> pi;
        p.push(pi);
    }
    for (int i = 0; i < h; ++i) {
        int qi; cin >> qi;
        q.push(qi);
    }
    ll ans = 0;
    for (int c = 0; c < h + w; ++c) {
        if (q.empty() || (!p.empty() && p.top() < q.top())) {
            ans += (ll)p.top() * (ll)(q.size() + 1);
            p.pop();
        } else {
            ans += (ll)q.top() * (ll)(p.size() + 1);
            q.pop();
        }
    }
    cout << ans;
    return 0;
}
