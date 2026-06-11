#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B; cin >> A >> B;
    if (A.size() != B.size()) {
        if (A.size() < B.size()) cout << "LESS" << endl;
        else cout << "GREATER" << endl;
    } else {
        if (A == B) {
            cout << "EQUAL" << endl;
        } else {
            int i = 0;
            while (A.at(i) == B.at(i)) {
                i++;
            }
            if (A.at(i) < B.at(i)) cout << "LESS" << endl;
            else cout << "GREATER" << endl;
        }
    }
}