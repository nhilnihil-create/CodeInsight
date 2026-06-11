#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
ll a[20];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> a[i];

    ll ans = 1.0e17;
    for (int i = 0; i < (1 << N); i++) {
        bitset<20> bt(i);
        if (bt.count() != K) continue;

        ll mx = 0;
        ll tmp = 0;
        for (int j = 0; j < N; j++) {
            if (bt[j] == 1) {
                if (mx < a[j]) {
                    mx = a[j];
                }
                else {
                    tmp += (mx + 1 - a[j]);
                    mx = mx + 1;
                }
            }
            else {
                mx = max(mx, a[j]);
            }
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    

    return 0;
}