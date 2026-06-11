#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    h = min (q*2, h);
    s = min (h*2, s);

    long long ans;
    if (s*2 <= d) ans = n*s;
    else ans = n/2*d + n%2*s;
    cout << ans << endl;
}