#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int MOD = 1e9+7;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vi a(N);
    rep(i, N) cin >> a[i];
    vi ans;
    rep(i, N) {
        rep(j, a[i]) ans.pb(i + 1);
    }
    vvi img(H, vi(W));
    rep(i, H) {
        rep(j, W) {
            img[i][j] = ans[i * W + j];
        }
    }
    rep(i, H) {
        if (i % 2 == 1)riverse(img[i]);
    }
    rep(i, H) {
        rep(j, W) {
            cout << img[i][j] << " ";
        }
        cout << endl;
    }
}