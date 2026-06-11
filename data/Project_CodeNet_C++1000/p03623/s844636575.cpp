#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, a, b;
    cin >> x >> a >> b;

    if (max(x - a, a - x) < max(x - b, b - x)) {
        cout << 'A' << endl;
    } else {
        cout << 'B' << endl;
    }
    return 0;
}