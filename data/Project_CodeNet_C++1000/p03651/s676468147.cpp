#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];

    int g = a[0];
    rep(i, n) { g = __gcd(g, a[i]); }

    if (k <= *max_element(a, a + n) && k % g == 0)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
