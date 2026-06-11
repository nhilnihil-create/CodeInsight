#include <iostream>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;


int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    Int pay = min(a+b, b+c);
    pay = min(pay, c+a);
    cout << pay << endl;
    return 0;
}
