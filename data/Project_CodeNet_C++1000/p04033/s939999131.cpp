#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= 0 && b >= 0) cout << "Zero" << endl;
    else if (a > 0 && b > 0 || a < 0 && b < 0 && abs(b - a - 1) % 2 == 0) cout << "Positive" << endl;
    else cout << "Negative" << endl;

    return 0;
}