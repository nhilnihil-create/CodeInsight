#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W, H;
    cin >> W >> H;
    vector<P> cost(W + H);
    rep(i, 0, W) {
        cin >> cost[i].first;
        cost[i].second = 0;
    }
    rep(i, 0, H) {
        cin >> cost[i + W].first;
        cost[i + W].second = 1;
    }
    sort(all(cost));
    ll ans = 0;
    ll a = W + 1, b = H + 1;
    rep(i, 0, cost.size()) {
        if (cost[i].second == 0) {
            ans += b * cost[i].first;
            a--;
        }
        else {
            ans += a * cost[i].first;
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}