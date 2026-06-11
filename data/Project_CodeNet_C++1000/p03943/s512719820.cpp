#include <iostream>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || b + c == a || c + a == b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
