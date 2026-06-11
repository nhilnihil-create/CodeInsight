#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[100005] = {}, b[100005] = {};
    ll z = 0, y = 1ll * mod * mod, x = 0, d[100005] = {};
    char c = '+';
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i > 1) cin >> c;
        if (c == '+') b[i] = 1;
        else b[i] = -1;
        cin >> a[i];
        z += a[i];
    }
    for (int i = 1; i <= n; i++) if (b[i] == -1) {
        d[i] = a[i];
        for (int j = i + 1; j <= n && b[j] == 1; j++) d[i] += a[j];
    }
    for (int i = 1; i <= n; i++) if (b[i] == -1) {
        y = min(y, x + d[i]);
        x += a[i];
    }
    if (x == 0) cout << z;
    else cout << z - y - y;
}
