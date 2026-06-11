#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char a, b;
    cin >> a >> b;
    if (a == 'H') {
        cout << b << endl;
    } else {
        cout << (b == 'H' ? 'D' : 'H') << endl;
    }
}
