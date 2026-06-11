#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long MOD = 1e9+7;
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x.at(i);
    }

    long long ans = 1;
    long long cnt = 1;
    for (int i = 0; i < n; i++) {
        if (x.at(i) < 2 * cnt - 1) {
            ans *= cnt;
            ans %= MOD;
        }
        else cnt++;
    }
  
    for (long long i = 2; i <= cnt - 1; i++) {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;
}