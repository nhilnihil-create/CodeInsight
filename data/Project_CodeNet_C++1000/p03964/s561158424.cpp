#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long ans, t_total, a_total;
    int t, a, n;
    cin >> n;
    cin >> t_total >> a_total;
    for (int i=0; i < n-1; ++i) {
        cin >> t >> a;
        long long p;
        p = max((t_total + t - 1) / t, (a_total + a - 1) / a);
        t_total = t*p; a_total = a*p;
    }
    ans = t_total + a_total;
    cout << ans;

}

int main() {

    solve();
    return 0;
}
