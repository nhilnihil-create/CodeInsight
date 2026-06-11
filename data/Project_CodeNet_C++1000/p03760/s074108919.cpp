#include <bits/stdc++.h>
using namespace std;

int main() {
    string o, e; cin >> o >> e;
    for (int i=0; i<o.size(); ++i) {
        cout << o[i];
        if (i != o.size()-1) cout << e[i];
        if (o.size() == e.size() && i == o.size()-1) {
            cout << e[i];
        }
    }
    cout << endl;
}
