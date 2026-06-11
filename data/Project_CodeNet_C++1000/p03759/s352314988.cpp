#include <iostream>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
