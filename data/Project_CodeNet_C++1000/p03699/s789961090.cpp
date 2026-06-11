#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int si, min_drop=105, ans=0;
    for (int i=0; i < n; ++i) {
        cin >> si;
        ans += si;
        if ((si % 10 != 0) && (si < min_drop))
            min_drop = si;
    }
    if (ans % 10 == 0) {
        if (min_drop < 100)
            ans -= min_drop;
        else
            ans = 0;
    }
    cout << ans;
}

int main() {

	solve();
    return 0;
}
