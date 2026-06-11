#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string o, e;
    cin >> o >> e;
    for (int i = 0; i < (int)e.size(); i++) {
        cout << o.at(i) << e.at(i);
    }
    if ((int)o.size() - (int)e.size() == 1) {
        cout << o.back();
    }
    return 0;
}