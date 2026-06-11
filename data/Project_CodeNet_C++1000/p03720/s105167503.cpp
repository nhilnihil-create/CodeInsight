#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ,m;
    cin >> n >> m;

    vector<int> a(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a.at(x-1) += 1;
        a.at(y-1) += 1;
    }

    for (int i = 0; i < n; i++) {
        cout << a.at(i) << endl;
    }

    return 0;
}
