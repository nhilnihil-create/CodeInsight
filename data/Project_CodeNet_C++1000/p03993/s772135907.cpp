#include <bits/stdc++.h>

using namespace std;

long long f(long long b, long long n) {
    if (b <= 1) return -1;
    if (n < b) return n;
    else return f(b, n / b) + n % b;
}
int A[100005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", A + i);
    int res = 0;

    for (int i = 1; i <= n; ++i) if (i == A[A[i]]) res++;

    printf("%d\n", res / 2);
    return 0;
}

