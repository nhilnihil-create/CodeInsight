#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<bool> f(n, false);
    int i = 0;
    int cnt = 0;
    while (1) {
        if (f.at(i)) {
            cout << -1 << endl;
            return 0;
        }
        else if (i == 1) {
            cout << cnt << endl;
            return 0;
        }
        else {
            f.at(i) = true;
            i = a.at(i) - 1;
            cnt++;
        }
    }
    return 0;
}