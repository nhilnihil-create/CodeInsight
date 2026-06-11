#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> w[n + 1];
    long long result[n + 1] = {};
    for (int i = 1; cin >> w[i].first; i++) {
        w[i].second = i;
    }
    sort(w + 1, w + n + 1);
    for (int i = n, j = n; i >= 1; i--) {
        j = min(j, w[i].second);
        result[j] += 1ll * (w[i].first - w[i - 1].first) * (n - i + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}
