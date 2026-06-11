#include <bits/stdc++.h>
using namespace std;

long long n, x;

int main() {

    cin >> n >> x;

    cout << 3 * (n - __gcd(n, x));

    return 0;

}
