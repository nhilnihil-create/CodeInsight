#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 206;
int ans[N];

int main() {
    ll C; cin >> C;
    int HiBit = 63 - __builtin_clzll(++C), n = 0;
    for (int i = HiBit - 1; i >= 0; i--) {
        if (((C>>i)&1) == 0) n++, ans[n] = n;
        else {
            n++, ans[n] = n;
            for (int i = 1; i <= n; i++) ans[i]++;
            n++, ans[n] = 1;
        }
    }
    cout << 2 * n << "\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";

    return 0;
}
