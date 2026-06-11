#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[2*(int)1e5], sum, ans = 10000000000LL, allsum;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        allsum += a[i];
    }
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i+1 < n) ans = min(ans, abs(allsum-2*sum));
    }
    cout << ans << endl;
    return 0;
}
