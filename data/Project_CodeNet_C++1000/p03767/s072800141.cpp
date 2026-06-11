#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(3 * n);

    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    int64_t ans = 0;

    for (int i = n; i < 3 * n; i += 2) {
        ans += a.at(i);
    }

    cout << ans << endl;
}
