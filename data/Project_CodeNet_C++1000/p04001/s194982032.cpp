#include <bits/stdc++.h>
//#include <ext/numeric>
#define oo 0x3f3f3f3f
#define long long long

using namespace std;
//using namespace __gnu_cxx;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(9), cout << fixed;

    string str;
    cin >> str;
    long ans = 0;
    for (int i = 0; i < (1 << ((int)str.size() - 1)); ++i) {
        long x = str[0] - '0';
        for (int j = 0; j < (int)str.size() - 1; ++j) {
            if (i & (1 << j)) {
                ans += x;
                x = 0;
            }
            x = x * 10 + str[j + 1] - '0';
        }
        ans += x;
    }

    cout << ans << '\n';

    return 0;
}
