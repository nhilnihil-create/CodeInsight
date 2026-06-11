#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans=0;
    for(int i=0; i<n; ++i) {
        int xi;
        cin >> xi;
        ans += 2*(min(abs(xi), abs(xi-k)));
    }
    cout << ans;
}

int main() {

	solve();
    return 0;
}
