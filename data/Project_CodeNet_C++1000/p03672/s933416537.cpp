#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int len = s.size() - 2;
    while (s.substr(0, len/2) != s.substr(len/2, len/2)) {
        //cout << s.substr(0, len/2) << " - " << s.substr(len/2, len/2) << endl;
        len -= 2;
    }
   // cout << s.substr(0, len/2) << " - " << s.substr(len/2, len/2) << endl;
    cout << len;
}

int main() {

	solve();
    return 0;
}
