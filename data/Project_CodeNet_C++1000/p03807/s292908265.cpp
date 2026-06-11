#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    int odd = 0;

    for (auto x : a) {
        if (x % 2 == 1) {
            odd++;
        }
    }
    if (odd % 2 == 0) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
}
