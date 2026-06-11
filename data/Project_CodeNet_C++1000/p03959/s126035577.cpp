#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> t(n), a(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> h(n, -1);
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        if(i == 0 || t[i] > t[i - 1]) {
            h[i] = t[i];
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1 || a[i] > a[i + 1]) {
            if(h[i] != -1 && h[i] != a[i]) {
                ans = 0;
            } else {
                h[i] = a[i];
            }
        } else if(h[i] != -1) {
            if(h[i] > a[i]) {
                ans = 0;
            }
        } else {
            (ans *= min(a[i], t[i])) %= MOD;
        }
    }
    cout << ans << endl;
}
