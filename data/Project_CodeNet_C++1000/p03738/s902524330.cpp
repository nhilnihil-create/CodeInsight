#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string res = "EQUAL";
    if (a.size() > b.size()) {
        res = "GREATER";
    } else if (a.size() < b.size()) {
        res = "LESS";
    } else {
        for (int i = 0; i < a.size(); i++) {
            if (a.at(i) > b.at(i)) {
                res = "GREATER";
                break;
            } else if (a.at(i) < b.at(i)) {
                res = "LESS";
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}
