#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5+7;
LL a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    LL ans = 0;
    for (int i = n; i > 0; i--) {
        a[i] += ans;
        LL z = (a[i]+b[i]-1)/b[i];
        ans += z*b[i]-a[i];
    }

    cout << ans << "\n";


    return 0;
}
