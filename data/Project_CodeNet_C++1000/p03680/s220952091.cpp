#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }
    int now = 1;
    int i = 1;
    while (1) {
        now = a.at(now);
        if (now == 2) {
            cout << i << endl;
            break;
        }
        i++;
        if (i > n) {
            cout << -1 << endl;
            break;
        }
    }
    return 0;
}
