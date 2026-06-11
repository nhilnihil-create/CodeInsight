#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cnt.at(a)++;
        cnt.at(b)++;
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt.at(i) << endl;
    }
    return 0;
}