#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> t(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t.at(i);
        sum += t.at(i);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        cout << sum + x - t.at(p) << endl;
    }
    return 0;
}