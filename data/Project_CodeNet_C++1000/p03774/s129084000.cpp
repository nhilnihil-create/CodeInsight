#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >>n >>m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >>a[i] >>b[i];
    }

    vector<int> c(m), d(m);
    for (int j = 0; j < m; j++) {
        cin >>c[j] >>d[j];
    }

    for (int i = 0; i < n; i++) {
        int cp, dist = 400000001;
        for (int j = 0; j < m; j++) {
            int t = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (t<dist) {
                dist = t;
                cp = j + 1;
            }
        }
        cout << cp << endl;
    }
    return 0;
}