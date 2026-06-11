#include <iostream>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << 1 << endl;
    } else if (a == b || b == c || c == a) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;
}
