#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        const long long pairsi = a[i] / 2;
        ans += pairsi;
        a[i] -= pairsi * 2;

        if (i == n - 1) continue;

        const long long pairsij = min(a[i], a[i + 1]);
        ans += pairsij;
        a[i] -= pairsij;
        a[i + 1] -= pairsij;
    }

    cout << ans << endl;
}
