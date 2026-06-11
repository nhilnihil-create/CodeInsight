#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> count(26, 0);
    vector<char> a(26);
    char b = 'a';
    for (int i = 0; i < 26; i++) {
        a.at(i) = b;
        b++;
    }
    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (S.at(i) == a.at(j)) count.at(j)++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count.at(i) == 0) {
            cout << a.at(i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}
