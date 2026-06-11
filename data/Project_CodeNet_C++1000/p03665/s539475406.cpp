#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    bool hasOdd = false;
    rep(i, n) {
        int a;
        cin >> a;
        if (a % 2 == 1) hasOdd = true;
    }

    ll ans = hasOdd ? pow(2, n - 1) : p == 1 ? 0 : pow(2, n);
    printf("%lld\n", ans);
    return 0;
}
