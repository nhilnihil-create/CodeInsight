#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
                ll l, r; cin >> l >> r;
                ans += (r - l + 1);
        }
        cout << ans << endl;

}
