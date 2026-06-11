#include<bits/stdc++.h>
using namespace std;

const int MAX = 200005;
long long A[MAX];

int main() {
    int N;
    long long a;
    scanf("%d", &N);
    A[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &a);
        A[i] = A[i-1] + a;
    }

    long long ans;
    ans = 2000000000;
    for (int i = 1; i < N; i++) {
        long long b;
        b = abs(A[i] - (A[N] - A[i]));
        ans = min(ans, b);
    }
    printf("%lld\n", ans);
    return 0;
}