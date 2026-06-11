#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
    ll n, capacity;
    cin >> n >> capacity;
    vector<ll> w(n+1), v(n+1);
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    // 重みをグループ分け
    ll w1 = w[1];
    vector<vector<ll>> items(4);
    vector<vector<ll>> vcumsum(4);
    for(int i = 1; i <= n; i++) items[w[i]-w1].push_back(v[i]);
    for(int i = 0; i < 4; i++) sort(items[i].begin(), items[i].end(), greater<ll>());
    for(int i = 0; i < 4; i++) {
        vcumsum[i].push_back(0);
        for(int j = 1; j <= items[i].size(); j++) {
            vcumsum[i].push_back(vcumsum[i][j-1] + items[i][j-1]);
        }
    }
    
    ll ans = -1;
    // どの重みの物をいくつ使うかで4重ループを回す。
    for(int i = 0; i <= items[0].size(); i++) {
        for (int j = 0; j <= items[1].size(); j++) {
            for (int k = 0; k <= items[2].size(); k++) {
                for (int l = 0; l <= items[3].size(); l++) {
                    ll total_w = i * w1 + j * (w1+1) + k * (w1+2) + l * (w1+3);
                    if (total_w > capacity) break;
                    ans = max(vcumsum[0][i] + vcumsum[1][j] + vcumsum[2][k] + vcumsum[3][l], ans);
                }
            }
        }
    }
    cout << ans << endl;
}