#include <iostream>
using namespace std;
int main() {
    int k, s, result = 0, x, y, z;
    cin >> k >> s;

    for (int i = 0; i <= k; ++i) {
        int n = s;
        x = i;
        n = n - x;
        for (int j = 0; j <= k; ++j) {
            int m = n;
            y = j;
            m = m - y;
            if (m >= 0)if (m <= k) result++;
        }
    }

    cout << result << endl;
}