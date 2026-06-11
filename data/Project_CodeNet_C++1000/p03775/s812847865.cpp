#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int calc_keta(ll a) {
    int ret = 0;
    if (a == 0) return 1;
    while(1) {
        if (a == 0) break;
        ++ret;
        a /= 10;
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a;
    a.push_back(1);
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) a.push_back(n/i);
    }
    int ans = 1e8;
    for (auto aa: a) {
        ll b = n / aa;
        int keta_a = calc_keta(aa);
        int keta_b = calc_keta(b);
        ans = min(ans, max(keta_a, keta_b));
    }
    cout << ans << endl;
    return 0;
}
