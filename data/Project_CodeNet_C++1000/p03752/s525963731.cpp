#include <iostream>
#include <bitset>
using namespace std;
const long long INF = 1LL<<60;

int main() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = INF;
    for (int bit = 0; bit < (1<<n); bit++) {
        int t = bitset<20>(bit).count();
        if (t < k) continue;
        long long cost = 0;
        int highest = a[0];
        for (int i = 1; i < n; i++) {
            if (bit & (1<<i) && a[i] <= highest) {
                cost += highest - a[i] + 1;
                highest++;
            }
            else {
                highest = max(highest, a[i]);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}