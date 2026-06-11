#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    ll ans = 1;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (x[i] < 2 * cnt + 1) {
            (ans *= (cnt + 1)) %= MOD;
            cnt--;
        }
        cnt++;
    }
    for (int i = 1; i <= cnt; i++) (ans *= i) %= MOD;
    cout << ans << endl;
}