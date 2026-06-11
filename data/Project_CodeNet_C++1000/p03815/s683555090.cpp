#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll x;
    cin >> x;
    ll ans = (x + 10) / 11 * 2;
    if(x % 11 <= 6 && x % 11 > 0) ans--;
    cout << ans << endl;
}