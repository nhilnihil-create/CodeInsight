#include <iostream>
using namespace std;
int main() {
    char c;
    for (int i = 0; i < 13; i++) {
        if (i == 4) cout << " ";
        else {
            cin >> c;
            cout << c;
        }
    }
    cout << endl;
}
