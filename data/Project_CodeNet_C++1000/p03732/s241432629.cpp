#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, int>;

int main() {
    int n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    rep(i, n)cin >> w[i] >> v[i];
    vector<vector<ll>> c(4);
    c[0].push_back(v[0]);
    for(int i = 1; i < n; i++)c[w[i]-w[0]].push_back(v[i]);
    rep(i, 4)sort(c[i].begin(), c[i].end(), greater<ll>());

    ll ans = 0;
    rep(i, c[0].size()+1)rep(j, c[1].size()+1)rep(k, c[2].size()+1)rep(l, c[3].size()+1){
        ll weight = i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3);
        if(weight > W)continue;
        ll sum = 0;
        for(int ii = 0; ii < i; ii++)sum += c[0][ii];
        for(int jj = 0; jj < j; jj++)sum += c[1][jj];
        for(int kk = 0; kk < k; kk++)sum += c[2][kk];
        for(int kk = 0; kk < l; kk++)sum += c[3][kk];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}