#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cng = -1;
    char c2 = 'a';
    for (char c: s) {
        if (c2 != c) {
            ++cng;
        }
        c2 = c;
    }
    cout << cng;
}

int main() {

    solve();
    return 0;
}
