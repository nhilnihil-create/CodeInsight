#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> t(n), a(n);
    rep(i, n) {
        cin >> t[i];
    }
    rep(i, n) {
        cin >> a[i];
    }

    vector<int> v(n);
    int now = 0;  // 現時点での最大値
    rep(i, n) {
        if(now < t[i]) {  // 最大値が変化したとき v[i] = t[i] が確定
            v[i] = t[i];
            now = t[i];
        }
    }

    now = 0;
    for(int i = n-1; i >= 0; i--) {
        if(v[i] == 0) {  // v[i]が未確定のときはt(n)と同様
            if(now < a[i]) {
                v[i] = a[i];
                now = a[i];
            }
        }
        else {  // v[i]が確定しているとき
            if(now < a[i] && v[i] != a[i]) {  // 最大値が変化するとv[i] = a[i]が確定するがa[i] != v[i]だと矛盾
                cout << 0 << endl;
                return 0;
            }
            else if(a[i] < v[i]) {  // 最大値はv[i]以上なのでa[i] < v[i]は矛盾
                cout << 0 << endl;
                return 0;
            }
            else if(now < v[i]) {
                now = v[i];
            }
        }
    }

    vector<ll> x(n);  // x[i] : v[i] = 0 のマスに書き込める数の種類(v[i] != 0 のときは0)
    now = v[0];
    rep(i, n) {
        if(now < v[i]) {
            now = v[i];
        }
        if(v[i] == 0) {
            x[i] = (ll)now;
        }
    }

    now = v[n-1];
    for(int i = n-1; i >= 0; i--) {
        if(now < v[i]) {
            now = v[i];
        }
        if(v[i] == 0) {
            x[i] = min(x[i], (ll)now);
        }
    }

    ll ans = 1LL;
    rep(i, n) {
        if(x[i] > 0) {
            ans *= x[i];
            ans %= mod;
        }
    }

    cout << ans << endl;
    return 0;
}