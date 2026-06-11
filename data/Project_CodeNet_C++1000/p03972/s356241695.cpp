#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int main() {
    int w, h; cin >> w >> h;
    vector<pair<int,int>> pq(w + h);
    REP(i, w) {
        cin >> pq[i].first;
        pq[i].second = 0;
    }
    REP(i, h) {
        cin >> pq[i+w].first;
        pq[i + w].second = 1;
    }
    ll ans = 0;
    sort(pq.begin(), pq.end());
    ll rest_w = w + 1, rest_h = h + 1;
    REP(i, w + h) {
        if (pq[i].second == 0) {
            ans += rest_h * pq[i].first;
            rest_w--;
        }
        else {
            ans += rest_w * pq[i].first;
            rest_h--;
        }
    }
    cout << ans << endl;
    return 0;
}