#include <iostream>
using namespace std;

int main() {
    unsigned int a, b;
    cin >> a >> b;
    a -= 2;
    b -= 2;
    if (a == b) {
        cout << "Draw" << endl;
    } else if (a < b) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}