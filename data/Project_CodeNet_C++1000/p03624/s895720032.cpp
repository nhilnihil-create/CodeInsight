#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    for (char c = 'a'; c <='z'; ++c) {
        bool flag = true;
        for (char si: s) {
            if (c == si) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << c;
            return;
        }
    }
    cout << "None";

}

int main() {

	solve();
    return 0;
}
