#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, a, b;
    cin >> x >> a >> b;

    if (b <= a) {
        cout << "delicious" << endl;
    } else if (a < b && b <= (a + x)) {
        cout << "safe" << endl;
    } else if (a + x < b) {
        cout << "dangerous" << endl;
    }

    return 0;
}