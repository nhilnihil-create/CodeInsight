#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (ll m = 0; m < n; m++) {
        ll e = m * c - (n - 1 - m) * d;
        ll f = a - b - e;
        if (f < 0) continue;
        if (d - c) {
            ll cnt = f / (d - c);
            f = f % (d - c);
            if (f) cnt++;
            if(cnt >= n) continue;
        } else if(f != 0) continue;
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}
