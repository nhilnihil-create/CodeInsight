#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    ll ans = T;
    for(int i = n - 2; i >= 0; i--){
        ans += min(T, t[i + 1] - t[i]);
    }
    cout << ans << endl;
}