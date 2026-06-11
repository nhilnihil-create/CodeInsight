#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll minv = a * (n - 1) + b;
    ll maxv = a + b * (n - 1);
    ll ans = maxv - minv + 1;

    cout << max(ans, 0ll) << endl;
    return 0;
}
