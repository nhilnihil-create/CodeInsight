#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> c;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            if (c.size()) c.pop_back();
        } else {
            c.push_back(s[i]);
        }
    }
    for (int i = 0; i < c.size(); i++) {
        cout << c[i];
    }
    cout << endl;
}
