#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;
const int mod = (int) 1e9 + 7;

ll a[Maxn], t[Maxn];
bool b[Maxn], c[Maxn];

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    t[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        if (t[i - 1] < t[i]) b[i] = true;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] > a[i + 1]) c[i] = true;
    }

    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (b[i] && c[i]) {
            if (t[i] != a[i]) ans = 0;
        } else if (b[i]) {
            if (t[i] > a[i]) ans = 0;
        } else if (c[i]) {
            if (a[i] > t[i]) ans = 0;
        } else {
            (ans *= min(t[i], a[i])) %= mod;
        }
    }

    cout << ans << endl;
}