#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && a % 2 == 0)cout << -1 << endl;
    else {
        for (int i = 0; true; i++) {
            if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
                cout << i << endl;
                break;
            }

            int x = b / 2 + c / 2, y = c / 2 + a / 2, z = a / 2 + b / 2;
            a = x, b = y, c = z;
        }
    }
    return 0;
}