#include <iostream>
using namespace std;

int main() {
    int64_t x, y;
    cin >> x >> y;

    if (-1 <= x - y && x - y <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }
    
    return 0;
}
