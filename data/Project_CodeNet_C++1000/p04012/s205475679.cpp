#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    if (S.size() % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    map<char, int> m;
    for (int i = 0; i < S.size(); i++) {
        if (m.count(S.at(i))) {
            m[S.at(i)]++;
        } else m[S.at(i)] = 1;
    }
    
    for (int i = 0; i < m.size(); i++) {
        if (m.at(S.at(i)) % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}