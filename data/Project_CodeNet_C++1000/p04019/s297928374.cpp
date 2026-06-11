#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    vector<int> cnt(4, 0);
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == 'N') {
            cnt.at(0)++;
        } else if (S.at(i) == 'E') {
            cnt.at(1)++;
        } else if (S.at(i) == 'S') {
            cnt.at(2)++;
        } else {
            cnt.at(3)++;
        }
    }
    if (cnt.at(0) * cnt.at(2) > 0 || (cnt.at(0) == 0 && cnt.at(2) == 0)) {
        if (cnt.at(1) * cnt.at(3) > 0 || (cnt.at(1) == 0 && cnt.at(3) == 0)) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    } else cout << "No" << endl;
}