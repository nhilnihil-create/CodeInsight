#include <bits/stdc++.h>

int main (void) {
    long long a, b, x;
    std::cin >> a >> b >> x;

    long long na; /* a 未満の x の倍数の個数 */
    long long nb; /* b 以下の x の倍数の個数 */
    na = a/x;
    if ( a % x == 0 ) na--;
    nb = b/x;

    std::cout << nb - na << std::endl;
    return 0;
}
