#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = b * (n - 1) + a - (a * (n - 1) + b) + 1;

    cout << max(0ll, ans) << endl;
    return 0;
}
