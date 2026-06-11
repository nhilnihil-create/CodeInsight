#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    long long int n, m, ans = 0;
    cin >> n >> m;
    int diff = abs(n-m);
    if (diff < 2) {
        long long int x = 1, y = 1;
        for(int i = 2; i <= n; ++i) {
            x *= i;
            x %= MOD;
        }
        for(int i = 2; i <= m; ++i) {
            y *= i;
            y %= MOD;
        }
        ans = (x*y)%MOD;
        if(diff == 0) ans = (ans*2)%MOD;
    }
    cout << ans << '\n';

    return 0;
}
