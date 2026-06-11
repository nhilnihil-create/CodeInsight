#include <bits/stdc++.h>
using namespace std;

int64_t lcm(int64_t a, int64_t b) {
    return (a / __gcd(a, b) * b);
}

int main(){
    int n; cin >> n;

    int64_t ans = 1;
    for (auto i = 0; i < n; i++) {
        int64_t t; cin >> t;
        ans = lcm(ans, t);
    }

    cout << ans << endl;
    return 0;
}