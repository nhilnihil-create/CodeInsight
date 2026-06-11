#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P  = pair<int, int>;

int main() {
    string s;
    int n;
    cin >> s;
    n      = s.size();
    ll ans = 0;
    rep(i, 1 << (n - 1)) {
        ll sum = 0;
        ll a   = s[0] - '0';
        rep(j, n - 1) {
            if(i & (1 << j)) {
                sum += a;
                a = 0;
            }
            a = a * 10 + s[j + 1] - '0';
        }
        sum += a;
        ans += sum;
    }
    cout << ans << endl;

    return 0;
}