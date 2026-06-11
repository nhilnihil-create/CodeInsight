#include <bits/stdc++.h>
using namespace std;


void solve () {
    long long n;
    cin >> n;
    int ans = (int) to_string(n).size();
    for (int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            int x = (int) to_string(n/i).size();
            int y = (int) to_string(i).size();
            ans = min (ans, max (x, y));
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
