#include <iostream>
using namespace std;

int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (long long i = 0; i < n; i++) {
        if (c * (n - 1 - i) - d * i <= b - a && b - a <= -c * i + (n - 1 - i) * d) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}