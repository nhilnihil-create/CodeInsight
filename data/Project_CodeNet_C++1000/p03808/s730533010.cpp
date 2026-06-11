#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    long long unit = 1LL * n * (n + 1) / 2;
    long long sum = accumulate(begin(a), end(a), 0LL);
    if (sum % unit) return !(cout << "NO" << endl);
    long long k = sum / unit;
    auto check = [&]() {
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            int d = a[(i + 1) % n] - a[i];
            if (k - d < 0 || (k - d) % n) return false;
            cnt += (k - d) / n;
        }
        return cnt == k;
    };
    cout << (check() ? "YES" : "NO") << endl;
    return 0;
}
