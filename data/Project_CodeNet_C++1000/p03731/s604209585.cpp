#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    ll n, t;
    ll ans = 0;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    for (int i = 1; i < n; i++) {
        if (a.at(i) - a.at(i - 1) > t) {
            ans += t;
        }
        else ans += a.at(i) - a.at(i - 1);
    }
    ans += t;
    cout << ans << endl;
}