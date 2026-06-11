#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long ans = 1;
    int n;
    long long mod = 1e9+7;
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
        (ans *= i) %= mod;
    cout << ans;

}

int main() {

    solve();
    return 0;
}

