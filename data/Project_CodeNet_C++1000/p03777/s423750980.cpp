#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    bool ans;
    if (a == 'H') {
        if (b == 'H') ans = true;
        else ans = false;
    } else {
        if (b == 'H') ans = false;
        else ans = true;
    }
    cout << (ans ? "H" : "D") << endl;
    return 0;
}