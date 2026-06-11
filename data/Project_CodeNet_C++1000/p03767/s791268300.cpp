#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i, 3*n)cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = n; i < 3 * n; i += 2){
        ans += a[i];
    }
    cout << ans << endl;
}