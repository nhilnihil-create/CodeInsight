#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    map<char, int> check;

    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S.size(); j++) {
            if (S.at(i) == S.at(j)) check[S.at(i)]++;
        }
    }

    for (int i = 0; i < S.size(); i++) {
        if (check[S.at(i)] != 1) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}