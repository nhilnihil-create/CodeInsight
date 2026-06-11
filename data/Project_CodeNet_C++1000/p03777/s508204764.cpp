#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;
    char a_, b_;
    cin >> a_ >> b_;
    if (a_ == 'H') a = 1;
    if (b_ == 'H') b = 1;

    if ((a + b) % 2 == 0) cout << "H" << endl;
    else
        cout << "D" << endl;

    return 0;
}