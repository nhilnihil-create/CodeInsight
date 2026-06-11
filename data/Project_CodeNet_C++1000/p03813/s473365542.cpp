#include <iostream>
#include <string>
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    int x;
    cin >> x;
    if (x < 1200) {
        cout << "ABC" << endl;
    } else {
        cout << "ARC" << endl;
    }
    return 0;
}
