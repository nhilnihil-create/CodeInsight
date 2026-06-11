#include<bits/stdc++.h>
using namespace std;

const int n = 50;
int A[n];

int main() {
    long long K;
    int n = 50;
    long long A[n];
    scanf("%lld", &K);
    for (int i = 0; i < n; i++) {
        int x = 0;
        if (i < K % n) x = 1;
        int y = K % n;
        if (i < K % n) y--;
        A[i] = i + K / n + n * x - y;
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%lld", A[i]);
    }
    return 0;
}
