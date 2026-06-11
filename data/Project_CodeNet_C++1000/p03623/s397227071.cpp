#include <iostream>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;


int main(void) {
    int x, a, b;
    cin >> x >> a >> b;
    int da = abs(x - a);
    int db = abs(x - b);
    if (da < db) {
        cout << 'A' << endl;
    } else {
        cout << 'B' << endl;
    }
    return 0;
}
