#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];
    vector<ll> diff_r(n);
    ll ans = 0;
    rep(i, 1, n) {
        ll tmp = (x[i]-x[i-1])*a;
        if(tmp >= b) {
            ans += b;
        }
        else {
            ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}