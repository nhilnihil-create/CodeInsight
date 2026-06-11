#include <iostream>

using namespace std;

int main() {
    long long int n, a, b;
    cin >> n >> a >> b;
    if (a > b || b - a > n) cout << 0;
    else cout << (b * (n - 1) + a) - (a * (n - 1) + b) + 1;
    return 0;
}