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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    ll q, h, s, d;
    ll n;
    cin >> q >> h >> s >> d >> n;
    ll ans = 0;
    if (n > 2) {
        ll q_2l = q * 8;
        ll h_2l = h * 4;
        ll s_2l = s * 2;
        ll min_2l = min({q_2l, h_2l, s_2l, d});
        ans += (n / 2) * min_2l;
        n -= n / 2 * 2;
    }
    if (n != 0) {
        ll q_1l = q * 4;
        ll h_1l = h * 2;
        ll min_1l = min({q_1l, h_1l, s});
        ans += min_1l;
    }
    cout << ans << endl;
    return 0;
}