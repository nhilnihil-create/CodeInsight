//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    vi x(n), y(n), a(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> a[i];
    }


    vvi aa(w, vi(h));
    rep(i, n) {
        switch(a[i]) {
            case 1:
                rep(j, x[i]) {
                    rep(k, h) {
                        aa[j][k] = 1;
                    }
                }
                break;
            case 2:
                for(int j = x[i]; j < w; ++j) {
                    rep(k, h) {
                        aa[j][k] = 1;
                    }
                }
                break;
            case 3:
                rep(j, w) {
                    rep(k, y[i]) {
                        aa[j][k] = 1;
                    }
                }
                break;
            case 4:
                rep(j, w) {
                    for(int k=y[i]; k < h; k++) {
                        aa[j][k] = 1;
                    }
                }
        }
    }


    int ans = 0;
    rep (i, w) {
        rep(j, h) {
            if(!aa[i][j]) {
                ans++;
            }
        }
    }

    

    cout << ans << endl;
}