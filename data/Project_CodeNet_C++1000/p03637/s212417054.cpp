#include <bits/stdc++.h>

using namespace std;

const int maxn = 100002;

int a[maxn];

int main() {
    int n;
    while (cin >> n) {
        int a4 = 0, a2 = 0, a1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 4 == 0) {
                a4++;
            } else if (a[i] % 2 == 0) {
                a2++;
            } else {
                a1++;
            }
        }
        if (a4 >= a1) {
            cout << "Yes" << endl;
        } else if (a4 + 1 == a1 && a2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}