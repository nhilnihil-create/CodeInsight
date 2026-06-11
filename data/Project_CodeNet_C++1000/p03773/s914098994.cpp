#include <iostream>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int a, b;
    cin >> a >> b;
    cout << (a + b) % 24 << endl; 
    return 0;
}
