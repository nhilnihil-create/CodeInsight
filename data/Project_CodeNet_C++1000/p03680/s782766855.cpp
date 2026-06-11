#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    int i = 0;
    int cnt = 0;
    while (1) {
        if (cnt >= n) {
            cout << -1 << endl;
            return 0;
        }
        else if (i == 1) {
            cout << cnt << endl;
            return 0;
        }
        else {
            i = a.at(i) - 1;
            cnt++;
        }
    }
    return 0;
}