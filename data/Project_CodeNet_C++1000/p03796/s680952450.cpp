#include <iostream>

using namespace std;

int main() {
    long n, amari = 1e9 + 7, power = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        power *= i;
        // cout << power;
        /*if (power > amari) {
            power %= amari;
            cout << ", " << power << endl;
            return 0;
        }*/
        power %= amari;
        // cout << ", " << power << endl;
    }

    cout << power << endl;
}