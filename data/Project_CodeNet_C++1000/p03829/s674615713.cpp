#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    ll ans = 0;
    for(int i = 1; i < n; i++){
        if((x[i] - x[i - 1]) * a < b) ans += (x[i] - x[i - 1]) * a;
        else ans += b;
    }
    cout << ans << endl;
}