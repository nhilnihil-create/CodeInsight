#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, a[2 * 100000];
    long long sum1 = 0, sum2 = 0, ans = 1e+17;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum2 += a[i];
    }

    sum1 += a[0], sum2 -= a[0];
    for(int i = 1; i < n; i++) {
        ans = min(ans, abs(sum1 - sum2));
        sum1 += a[i], sum2 -= a[i];
    }
    cout << ans << endl;
}
