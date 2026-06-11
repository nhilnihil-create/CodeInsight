#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int p = 0, f = 0;
    for (int i = 0; i < n; i++) {
        char c = s.at(i);
        if (c == 'c') {
            cout << "No" << endl;
        }
        else if (p >= a + b) {
            cout << "No" << endl;
        }
        else if (c == 'a') {
            p++;
            cout << "Yes" << endl;
        }
        else if (c == 'b') {
            if (++f <= b) {
                p++;
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}