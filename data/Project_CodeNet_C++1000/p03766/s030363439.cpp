#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll n, d[1000006] = {}, c = 0;
    cin >> n;
    d[0] = 1; d[1] = n; d[2] = n * n % mod; c = n - 1;
    for (int i = 3; i <= n; i++) {
        c = (c + d[i - 3] - 1) % mod;
        d[i] = (d[i - 1] + (n - 1) * (n - 1) + c) % mod;
    }
    cout << d[n] << '\n';
}
