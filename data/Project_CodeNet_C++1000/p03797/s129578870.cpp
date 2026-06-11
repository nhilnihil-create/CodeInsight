#include <iostream>
using namespace std;

long long int n, m;

int main() {
    cin >> n >> m;
    if (n * 2 >= m) cout << (m / 2) << endl;
    else {
        cout << (n + ((m - 2 * n) / 4)) << endl;
    }

    return 0;
}