#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int m = n * 2 - 1;
        if ((m + 1) / 2 <= x) {
            for (int i = m / 2; i >= 1; i--) {
                cout << i << endl;
            }
            cout << x << endl;
            for (int i = m; i >= (m + 1) / 2; i--) {
                if (i == x) continue;
                cout << i << endl;
            }
        }
        else {
            for (int i = (m + 1) / 2; i >= 1; i--) {
                if (i == x) continue;
                cout << i << endl;
            }
            cout << x << endl;
            for (int i = m; i >= (m + 1) / 2 + 1; i--) {
                cout << i << endl;
            }
        }
    }
}