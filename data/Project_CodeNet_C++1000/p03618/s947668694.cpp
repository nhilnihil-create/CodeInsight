#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    cin >> a;

    auto n = (long long) a.length();
    auto ans = n * (n - 1) / 2 + 1LL;

    long long c[26] = {};
    for (int i = 0; i < n; ++i) {
        c[a[i] - 'a']++;
    }

    for (auto cc:c) {
        ans -= cc * (cc - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}