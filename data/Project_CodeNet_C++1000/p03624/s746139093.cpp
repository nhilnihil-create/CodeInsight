#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    vector<char> a(S.size());
    map<char, int> hey;
    for (char x = 'a'; x <= 'z'; x++) hey[x] = 0;
    for (int i = 0; i < S.size(); i++) {
        a.at(i) = S.at(i);
        hey.at(a.at(i))++;
    }
    for (char x = 'a'; x <= 'z'; x++) {
        if (hey.at(x) == 0) {
            cout << x << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}