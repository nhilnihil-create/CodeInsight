#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    if ((a == 0 || b == 0) || (a < 0 && b > 0)) {
        cout << "Zero" << endl;
        return 0;
    }

    if (a > 0 && b > 0)
        cout << "Positive" << endl;
    else // a < 0 && b < 0
        cout << ((b - a) % 2 == 0 ? "Negative" : "Positive") << endl;
}