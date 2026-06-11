#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    uint64_t sum = 0;
    uint32_t n; cin >> n;
    vector<uint32_t> t(n);
    for (auto &e : t) {
        cin >> e;
        sum += e;
    }
    uint32_t m; cin >> m;

    uint32_t p, x;
    while (m--) {
        cin >> p >> x;
        cout << (sum - t[p - 1] + x) << endl;
    }
}

