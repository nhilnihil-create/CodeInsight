#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }

    int p = 1;
    for (int i = 0; i < n; ++i) {
        int tempMin = abs(a[i] - c[0]) + abs(b[i] - d[0]);
        for (int j = 0; j < m; ++j) {
            int ans = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (tempMin > ans) {
                p = j + 1;
                tempMin = ans;
            }
        }
        cout << p << endl;
        p = 1;
    }


}