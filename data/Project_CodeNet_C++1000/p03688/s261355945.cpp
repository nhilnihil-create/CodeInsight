#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    bool ok = false;
    if (m.size() == 1) {
        int a = m.begin() -> first;
        if (a == n - 1 || 2 * a <= n) ok = true;
    }
    else if (m.size() == 2) {
        int x = m.begin() -> second, y = m.rbegin() -> second;
        int a = m.rbegin() -> first;
        int b = m.begin() -> first;
        if (a - b == 1 && x < a && 2 * (a - x) <= y) ok = true;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}