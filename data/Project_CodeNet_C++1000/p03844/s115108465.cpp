#include <iostream>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int a, b;
    char op;
    cin >> a >> op >> b;
    if (op == '+') {
        cout << a + b << endl;
    } else if (op == '-') {
        cout << a - b << endl;
    }
    return 0;
}
