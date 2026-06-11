#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p  = pair<ll, ll>;
constexpr ll INF = 1LL << 62;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll H, W, N;
    cin >> H >> W >> N;
    
    unordered_map<ll, ll> m;
    
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        
        for (ll dh = -1; dh <= 1; dh++) {
            for (ll dw = -1; dw <= 1; dw++) {
                if (a + dh < 0 || a + dh > H - 1 || b + dw < 0 || b + dw > W - 1) {
                    continue;
                }
                m[(a + dh) * W + (b + dw)] += 1;
            }
        }
    }
    
    vector<ll> ans(10, 0);
    ll non_zero = 0;
    
    for (auto&& a : m) {
        ll h = a.first / W;
        ll w = a.first % W;
        if (h <= 0 || h >= H - 1 || w <= 0 || w >= W - 1) {
            continue;
        }
        ans[a.second] += 1;
        non_zero += 1;
    }
    
    ans[0] = (H - 2) * (W - 2) - non_zero;
    for (auto a : ans) {
        cout << a << endl;
    }
    
    return 0;
}
