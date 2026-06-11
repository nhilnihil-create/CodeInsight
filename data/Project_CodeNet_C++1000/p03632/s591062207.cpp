#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, result;
    cin >> a >> b >> c >> d;

    if (a < c) {
        if (min(b, d) >= c) {
            result = min(b, d) - c;
        } else {
            result = 0;
        }

    } else if (a > c) {
        if (min(b, d) >= a) {
            result = min(b, d) - a;
        } else {
            result = 0;
        }

    } else {
        result = min(b, d) - a;
    }
    cout << result << endl;
}