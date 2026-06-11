#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ma = 0, x = 0;
    for (int i = 0; i < n; i++) {
        char c = s.at(i);
        if (c == 'I') {
            x++;
            ma = max(ma, x);
        }
        else {
            x--;
        }
    }
    cout << ma << endl;
    return 0;
}