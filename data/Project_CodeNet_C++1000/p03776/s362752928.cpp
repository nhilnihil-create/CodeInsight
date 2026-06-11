#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long comb(int n, int r) {
    if (r < 0 || n < r) return 0;
    long long ret = 1;
    for (int i = 1; i <= r; i++) (ret *= n--) /= i;
    return ret;
}

#include <iomanip>
int main() {
    cout << fixed << setprecision(12);
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<long long> v(n);
    for (auto &vi: v) cin >> vi;
    sort(v.rbegin(), v.rend());
    auto sum = accumulate(begin(v), begin(v) + a, 0.0);
    cout << sum / a << endl;
    int l = a - 1, r = a - 1;
    while (l > 0 && v[l - 1] == v[a - 1]) l--;
    while (r + 1 < n && v[r + 1] == v[a - 1]) r++;
    if (l == 0) {
        long long cnt = 0;
        for (int i = a; i <= b; i++) cnt += comb(r + 1, i);
        cout << cnt << endl;
    } else {
        cout << comb(r - l + 1, a - l) << endl;
    }
    return 0;
}
