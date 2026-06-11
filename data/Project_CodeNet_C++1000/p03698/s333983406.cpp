#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    char prev = s.at(0);
    for (int i = 1; i < (int)s.size(); i++) {
        if (s.at(i) == prev) {
            cout << "no" << endl;
            return 0;
        }
        prev=s.at(i);
    }
    cout << "yes" << endl;
    return 0;
}