#include <iostream>
using namespace std;

using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c >= a && c <= b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
