#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
 
    if (a.length() > b.length()) {
        cout << "GREATER" << endl;
    } else if (a.length() < b.length()) {
        cout << "LESS" << endl;
    } else {
        bool equal = true;
        for (int i = 0; i < a.length(); i++) {
            if (a.at(i) > b.at(i)) {
                cout << "GREATER" << endl;
                equal = false;
                break;
            } else if (a.at(i) < b.at(i)) {
                cout << "LESS" << endl;
                equal = false;
                break;
            } else {
                continue;
            }
        }
        if (equal) {
            cout << "EQUAL" << endl;
        }
    }
}
