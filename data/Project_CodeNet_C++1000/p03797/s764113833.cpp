#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n,m, ans = 0;
    cin >> n >> m;
    ans = min(n, m/2);
    n = n - ans;
    m = m - ans*2;
    if (n == 0) {
        ans += m / 4;
        cout << ans;
        return;
    } else {
        cout << ans;
        return;
    }


}

int main() {

    solve();
    return 0;
}
