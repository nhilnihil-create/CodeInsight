#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int64_t X, Y;
    cin >> X >> Y;
    if(abs(X-Y) <= 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }
    return 0;
}
