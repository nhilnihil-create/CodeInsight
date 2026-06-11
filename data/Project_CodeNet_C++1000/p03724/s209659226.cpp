#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> cnt(n);
    while (m--) {
        int a, b; cin >> a >> b; a--, b--;
        cnt[a]++, cnt[b]++;
    }
    bool ok = all_of(begin(cnt), end(cnt), [&](auto &e) { return e % 2 == 0; });
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
