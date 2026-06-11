#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    scanf("%ld", &n);
    long a[n];
    for (long i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    long i = n - 1;
    printf("%ld", a[i]);
    i -= 2;
    for ( ; i >= 0; i -= 2) {
        printf(" %ld", a[i]);
    }
    if (n % 2 == 0) i = 0;
    else i = 1;
    for ( ; i < n; i += 2) {
        printf(" %ld", a[i]);
    }
    printf("\n");
}