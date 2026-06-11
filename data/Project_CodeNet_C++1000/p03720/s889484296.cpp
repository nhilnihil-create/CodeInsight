#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v.at(--a)++;
        v.at(--b)++;
    }

    for (int x : v)
        cout << x << endl;
}