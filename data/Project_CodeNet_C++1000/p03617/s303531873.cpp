#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    h = min(h, 2 * q);
    s = min(s, 2 * h);
    // cout << s << ' ' << d << endl;
    // cout << n / 2 * d + (n % 2) * s << endl;
    cout << min(n * s, n / 2 * d + (n % 2) * s) << endl;
}
