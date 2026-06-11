#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans;
    cin >> ans;
    n--;
    while(n--) {
        long long x;
        cin >> x;
        ans = ans / __gcd(x, ans) * x;
    }
    cout << ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
