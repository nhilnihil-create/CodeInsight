#include <bits/stdc++.h>
using namespace std;

int main() {
    string o, e;
    cin >> o >> e;

    for (int i = 0; i < o.size(); i++) {
        cout << o.at(i);
        if (i < e.size()) cout << e.at(i);
    }

    cout << endl;

    return 0;
}
