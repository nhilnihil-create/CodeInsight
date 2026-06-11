#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    long long a, b; cin >> a >> b;
    vector<int> x(n);
    for (auto &xi: x) cin >> xi;
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        ans += min(a * (x[i + 1] - x[i]), b);
    }
    cout << ans << endl;
    return 0;
}
