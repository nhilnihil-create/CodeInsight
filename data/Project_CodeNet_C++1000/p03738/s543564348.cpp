#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size()) {
        cout << "GREATER" << endl;
    } else if (a.size() < b.size()) {
        cout << "LESS" << endl;
    } else {
        if (a[0] > b[0]) {
            cout << "GREATER" << endl;
        } else if (b[0] > a[0]) {
            cout << "LESS" << endl;
        } else {
            cout << "EQUAL" << endl;
        }
    }

    return 0;
}