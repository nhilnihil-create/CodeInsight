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

int n, k, a[100000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll r = 0, c = 0, d = 0;
    for (int i = 0; i < k; i++) c += a[i];
    for (int i = k; i < n; i++) d += max(0, a[i]);
    r = max(c + d, d);
    for (int i = 0; i < n - k; i++) {
        d += max(0, a[i]) - max(0, a[i + k]);
        c += a[i + k] - a[i];
        r = max(r, max(c + d, d));
    }
    cout << r << endl;
}