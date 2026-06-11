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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll now = 1;
    for(int i = 0; i < n; i++) {
        // cout << "---" << endl;
        // cout << now << ' ' << ans << endl;
        // for(auto j : a) {
        //     cout << j << ' ';
        // }
        // cout << endl;
        if(a[i] == now) {
            now++;
        } else if(a[i] % now == 0) {
            ans += (a[i] - 1) / now;
            if(now == 1) {
                a[i] = 1;
                now++;
            } else {
                a[i] = now - 1;
            }
        } else {
            ll num = (a[i] - 1) / now;
            ans += num;
            a[i] -= now * num;
            if(a[i] >= now) {
                now = a[i] + 1;
            }
        }
    }
    // cout << "---" << endl;
    // cout << now << ' ' << ans << endl;
    // for(auto j : a) {
    //     cout << j << ' ';
    // }
    // cout << endl;
    cout << ans << endl;
}