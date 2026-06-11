#include <bits/stdc++.h>
using namespace std;
long long digit(long long n) {
    long long r = 0;
    while (n != 0)
    {
        r++;
        n /= 10;
    }
    return r;
}
int main() {
    long long n, d;
    cin >> n;
    d = digit(n);
    for (long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            d = min(d, max(digit(i), digit(n / i)));
    }
    cout << d;
}