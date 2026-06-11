#include <bits/stdc++.h>
using namespace std;

string o, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> o >> e;

    int id1 = 0, id2 = 0;
    for (int i = 0; i < o.size() + e.size(); i++) {
        if (i&1) {
            cout << e[id2++];
        }
        else {
            cout << o[id1++];
        }
    }
    cout << '\n';

    return 0;
}