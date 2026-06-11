#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= 0 && b >= 0) {
        cout << "Zero\n";
        return 0;
    }
    if (a > 0 && b > 0) {
        cout << "Positive\n";
        return 0;
    }
    cout << ((b - a) % 2 ? "Positive" : "Negative") << '\n';
    return 0;
}
