#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> mp;
    while (m--) {
        int a, b;
        cin >> a;
        cin >> b;
        mp[a]++;
        mp[b]++;
    }

    for (auto &x :mp) {
        if ((x.second) % 2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}