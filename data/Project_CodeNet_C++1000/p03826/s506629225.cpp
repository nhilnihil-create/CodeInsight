#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    UInt a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(a * b, c * d) << endl;
    return 0;
}
