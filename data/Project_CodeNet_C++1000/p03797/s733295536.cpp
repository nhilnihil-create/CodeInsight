#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int  main() {
    ll N, M;
    ll ans = 0;
    cin >> N >> M;
    ll s_count;
    ll c_count;

    s_count = N;
    c_count = M/2;
    if (s_count > c_count) {
        cout << c_count << endl;
    } else {
        ans += s_count;
        M -= 2 * s_count;
        ans += M / 4;
        cout << ans << endl;
    }

}
