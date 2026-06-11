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
    int n;
    ll x;
    cin >> n >>x;
    ll ans = 0;
    ll now = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        if(!i) {
            if(a>x) {
                ans += a-x;
                now = x;
            } else {
                now = a;
            }
        }
        else {
            if(now+a<=x) {
                now = a;
            } else {
                ans += now+a-x;
                now = x-now;
            }
        }
    }

    cout << ans << endl;
}