#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No";
    } else {
        cout << "Yes\n";
        if (x < n) {
            for (int i = n + x; i < 2 * n; i++) {
                cout << i << ' ';
            }
            for (int i = 1; i < n + x; i++) {
                cout << i << ' ';
            }
        } else {
            for (int i = x - n + 1; i < 2 * n; i++) {
                cout << i << ' ';
            }
            for (int i = 1; i < x - n + 1; i++) {
                cout << i << ' ';
            }
        }
    }
    return 0;
}
