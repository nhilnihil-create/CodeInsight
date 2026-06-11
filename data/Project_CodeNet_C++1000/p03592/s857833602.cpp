#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j * n + i * m - 2 * i * j == k) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}