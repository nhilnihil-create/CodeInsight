#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b < 0) {
        if ((b-a)%2) cout << "Positive" << endl;
        else cout << "Negative" << endl;
    }
    else if (a > 0) {
        cout << "Positive" << endl;
    }
    else cout << "Zero" << endl;
}