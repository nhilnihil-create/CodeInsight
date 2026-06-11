#include <bits/stdc++.h>
using namespace std;
long long ceilint(long long m, long long n) {
    if (m % n == 0) return m / n;
    else return m / n + 1;
}
int main() {
    long long a, b, x;
    cin >> a >> b >> x;
    cout << b / x - ceilint(a, x) + 1;
}