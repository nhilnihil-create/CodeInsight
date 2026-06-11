#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f; 
}

const int Max = 100033;
int n, a[Max];
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

bool solve() {
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) {
            if (a[i] == 1) return 0;
            else { a[i]--; break; }
        }
    }
    int d = a[1];
    for (int i = 2; i <= n; i++) d = gcd(d, a[i]);
    for (int i = 1; i <= n; i++) a[i] /= d;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
    	if (a[i] & 1) odd++;
    	else even ^= 1;
    }
    if (!even && odd == 1) return solve() ^ 1;
    else return (even ? 0 : 1);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) odd++;
        else even ^= 1;
    }
    if (!even && odd == 1)
        puts(solve() ? "First" : "Second");
    else puts(even ? "First" : "Second");
    return 0;
}