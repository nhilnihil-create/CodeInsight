#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> t(n);
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }

    for (int i = 1; i < n; i++) {
        long long tx = (t[i-1] + t[i] - 1) / t[i];
        long long ax = (a[i-1] + a[i] - 1) / a[i];
        t[i] *= max(tx, ax); a[i] *= max(tx, ax);
    }
    long long ans = t[n-1] + a[n-1];
    cout << ans << endl;
    return 0;
}