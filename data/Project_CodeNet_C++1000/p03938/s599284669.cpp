#include <bits/stdc++.h>

using namespace std;


int p[20005];
int A[20005];
int B[20005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        A[a] += i + 1;
        A[i + 1] += 25000 * (i + 1);
    }
    for (int i = 1; i <= n; ++i) B[i] =  25000 * (n - i + 1);

    for (int i = 1; i < n; ++i) printf("%d ", A[i]);
    printf("%d\n", A[n]);
    for (int i = 1; i < n; ++i) printf("%d ", B[i]);
    printf("%d\n", B[n]);


    return 0;
}
