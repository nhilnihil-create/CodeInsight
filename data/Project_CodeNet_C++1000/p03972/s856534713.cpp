#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int64 W, H;
    cin >> W >> H;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, 0, W + H) {
        int p; cin >> p;
        pq.push({p, i >= W});
    }
    W++, H++;
    int64 ans = 0;
    while(!pq.empty()) {
        P t = pq.top(); pq.pop();
        if(t.second) {
            ans += W * t.first;
            H--;
        }
        else {
            ans += H * t.first;
            W--;
        }
    }
    cout << ans << endl;
    return 0;
}
