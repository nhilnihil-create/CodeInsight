#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll x, t;
    cin >> x >> t;

    cout << max(x - t, 0ll) << endl;
    return 0;
}
