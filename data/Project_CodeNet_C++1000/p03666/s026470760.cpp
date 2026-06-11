#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (int i = 0; i <= n - 1; i++) {
        long long minimum = c * i - d * (n - 1 - i), maximum = d * i - c * (n - 1 - i);
        if (minimum <= b - a && b - a <= maximum) {
            cout << "YES" << endl;
            return 0;
        } 
    }
    cout << "NO" << endl;
}