#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool r = false;
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++) {
        if (s.at(i-1) == s.at(i)) r = true;
    }
    
    if (r) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }

    return 0;
}
