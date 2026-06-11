#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    int f[7] = {1, 3, 5, 7, 8, 10, 12};
    int s[4] = {4, 6, 9, 11};
    int counterf = 0;
    int counters = 0;
    for (int i = 0; i < 7; i++) {
        if (x == f[i]) {
            counterf++;
        }
        if (y == f[i]) {
            counterf++;
        }
    }
    for (int j = 0; j < 4; j++) {
        if (x == s[j]) {
            counters++;
        }
        if (y == s[j]) {
            counters++;
        }
    }
    if (x == 2 && y == 2) {
        cout << "Yes";
        return 0;
    }
    if (counterf == 2 || counters == 2) {
        cout << "Yes";
        return 0;
    }
    if (counterf < 2 || counters < 2) {
        cout << "No";
        return 0;
    }
}