#include <iostream>

using namespace std;

int main() {
    int w, a, b;
    cin >> w >> a >> b;

    if (b <= w + a && a <= w + b) {
        cout << 0 << endl;
    }
    else if (a <= b) {
        cout << b - (a + w) << endl;
    }
    else {
        cout << a - (b + w) << endl;
    }
}
