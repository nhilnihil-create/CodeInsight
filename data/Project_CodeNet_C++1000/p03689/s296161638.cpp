#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
const int N = 500 + 5;
int n, m, a, b;
int read() {
    char c; int x = 0, f = 1;
    c = getchar();
    while (c > '9' || c < '0') { if(c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int main() {
    n = read(), m = read(), a = read(), b = read();
    if(n % a == 0 && m % b == 0) puts("No");
    else {
        puts("Yes");
        rep(i, 1, n / a * a) {
            rep(j, 1, m) {
                if(i % a == 0 && j % b == 0) printf("%d ", -500 * (a * b - 1) - 1);
                else printf("500 ");
            }
            puts("");
        }
        rep(i, n / a * a + 1, n) {
            rep(j, 1, m) printf("500 ");
            puts("");
        }
    }
    return 0;
}