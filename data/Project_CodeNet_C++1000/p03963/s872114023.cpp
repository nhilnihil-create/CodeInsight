#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, k, ans;
    cin >> n >> k;
    ans = k;
    for (int i = 0; i < n-1; ++i ) {
        ans *= k-1;
    }
    cout << ans;
}

int main() {

    solve();
    return 0;
}
