#include <iostream>
#include <algorithm>

using namespace std;

char alph[26];

void solve() {
    string s;
    cin >> s;
    for (char c: s) {
        ++alph[c - 'a'];
        if (alph[c-'a'] > 1) {
            cout <<"no";
            return;
        }
    }
    cout << "yes";

}

int main() {

	solve();
    return 0;
}

