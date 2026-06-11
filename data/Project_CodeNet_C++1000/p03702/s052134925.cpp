#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7, INF = 1e9 + 10;


vector<ll> vec;

ll n, a, b;

bool check(ll exp) {
    ll ext = 0;
    for (auto cur : vec) {
        if (cur > exp * b) {
            ll q = cur - exp * b;
            ext += (q - 1) / (a - b) + 1;
        }
    }
    if (ext <= exp) return true;
    return false;
}

int main() {
    fastInp;

    cin >> n >> a >> b;

    ll l = -1, r = INF;

    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << r;
    return 0;
}

