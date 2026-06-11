#include <iostream>
using namespace std;

int main (void) {

    int n, m;

    cin >> n >> m;

    if (m < n) {
        if (m == 1) {
            cout << "Bob" << endl;
        }else if(n != 1) {
            cout << "Alice" << endl;
            }
        }
    
    if (n < m) {
        if (n == 1) {
            cout << "Alice" << endl;
        }else if(n != 1) {
            cout << "Bob" << endl;
            }
    }

    if (n == m) {
        cout << "Draw" << endl;
    }

    return 0;
}
