#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    int sum_t = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t.at(i) = x;
        sum_t += x;
    }

    int m;
    cin >> m;

    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        int a, x;
        cin >> a >> x;
        p.at(i) = x - t.at(--a);
    }

    for (int i = 0; i < m; i++)
        cout << (sum_t + p.at(i)) << endl;
}