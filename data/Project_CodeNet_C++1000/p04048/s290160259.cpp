#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n, x;
    cin >> n >> x;
    LL ans = n;
    LL a = x, b = n-x;
    if(a > b) swap(a, b);
    while(a) {
        LL k = b/a;
        ans += 2*k*a;
        b %= a;
        if(b == 0) ans -= a;
        swap(a, b);
    }
    cout << ans << endl;
    return 0;
}

