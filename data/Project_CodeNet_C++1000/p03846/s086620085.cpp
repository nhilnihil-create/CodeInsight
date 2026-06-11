#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    uint32_t n; cin >> n;
    vector<uint32_t> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());

    if ((n & 1) && a[0] != 0) {
        cout << 0 << endl;
        return 0;
    }

    uint64_t ans = 1;
    for (auto i = a.begin() + (n & 1); i != a.end(); i += 2, ans = (ans * 2) % 1000000007) {
        if ((*i == 0 || *(i + 1) == 0) || *i != *(i + 1)) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}

