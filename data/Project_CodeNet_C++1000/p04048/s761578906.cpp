#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long n, x;
    cin >> n >> x;
    long res = n;
    long a = x;
    long b = n - x;
    if (a < b) swap(a, b);
    while (a != b) {
         long t = (a - 1) / b;
         res += b * 2 * t;
         a -= b * t;
         swap(a, b);
    }
    res += a;
    cout << res;

    return 0;
}