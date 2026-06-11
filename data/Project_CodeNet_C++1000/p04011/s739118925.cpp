#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    int ans = 0;

    for (int i=1; i<=n; ++i) {
        if (i<=k) ans += x;
        else ans += y;
    }

    cout << ans << endl;
    
    return 0;
}
