#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, ans =0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int li, ri;
        cin >> li >> ri;
        ans += ri-li+1;
    }
    cout << ans;
}

int main() {

	solve();
    return 0;
}
