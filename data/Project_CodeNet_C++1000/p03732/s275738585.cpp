#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main() {
    int N;  cin >> N;
    ll W;   cin >> W;
    vector<ll> w(N), v(N);
    rep(i, N)
        cin >> w[i] >> v[i];
    ll w1 = w[0];

    vector<vector<ll> > c(4);
    rep(i, N) {
        c[w[i]-w1].push_back(v[i]);
    }
    rep(i, 4)
        sort(c[i].begin(), c[i].end(), greater<ll>());
    vector<vector<ll> > s(4);
    rep(i, 4) {
        int l = c[i].size();
        s[i].resize(l+1, 0);
        rep(j, l) {
            s[i][j+1] = s[i][j] + c[i][j];
        }
    }
    ll ans = 0;
    rep(i, c[0].size()+1) {
        rep(j, c[1].size()+1) {
            rep(k, c[2].size()+1) {
                rep(l, c[3].size()+1) {
                    if (w1*(i+j+k+l) + j+2*k+3*l > W)
                        continue;
                    ans = max(ans, s[0][i] + s[1][j] + s[2][k] + s[3][l]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}