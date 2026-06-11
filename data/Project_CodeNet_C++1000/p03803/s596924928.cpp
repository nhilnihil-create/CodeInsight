#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        a += 13;
    }
    if (b == 1) {
        b += 13;
    }
    if (a > b) {
        cout << "Alice" << endl;
    } else if (a < b) {
        cout << "Bob" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}
