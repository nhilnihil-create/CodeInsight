#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;

    if (s.size() == 2) {
        if (s.at(0) == s.at(1)) {
            cout << 1 << " " << 2 << endl;
            return 0;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
            return 0;
        }
    }
    else {
        for (int i = 0; i < s.size() - 1; i++) {
            if(s.at(i) == s.at(i + 1)) {
                cout << i + 1 << " " << i + 2 << endl;
                return 0;
            }
            else if (i < s.size() - 2 && s.at(i) == s.at(i + 2)) {
                cout << i + 1 << " " << i + 3 << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << endl;
    
}
