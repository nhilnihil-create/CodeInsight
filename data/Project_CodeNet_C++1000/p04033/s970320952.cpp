#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > 0) {
        cout << "Positive" << '\n';
    } else if (b >= 0) {
        cout << "Zero" << '\n';
    } else {
        int x = b - a + 1;
        if (x & 1) {
            cout << "Negative" << '\n';
        } else {
            cout << "Positive" << '\n';
        }
    }
    
    return 0;
}
