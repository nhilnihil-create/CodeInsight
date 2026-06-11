#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    ll n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ans += i;
    }
    cout << ans << endl;
    return 0;
}