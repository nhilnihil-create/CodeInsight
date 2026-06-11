//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll sum = 0, ans = LINF, now = 0;
    int x = 1, x_ = -1;
    int *y, *y_;
    y = &x;
    y_ = &x_;
    rep(qq, 2) {
        rep(i, n) {
            if(*y == 1) {
                if(a[i]+sum <= 0) {
                    now += 1-sum-a[i];
                    sum = 1;
                } else {
                    sum += a[i];
                }
            } else {
                if(a[i]+sum >= 0) {
                    now += a[i]+sum+1;
                    sum = -1;
                } else {
                    sum += a[i];
                }
            }
            swap(y, y_);
        }
        if(*y == 1) swap(y, y_);
        ans = min(ans, now);
        sum = 0;
        now = 0;
    }

    cout << ans << endl;
}