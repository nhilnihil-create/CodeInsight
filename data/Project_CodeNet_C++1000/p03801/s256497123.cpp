#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

long long A[MAX], B[MAX], C[MAX], D[MAX], s[MAX];

int main() {
    int N;
    long long a;
    scanf("%d", &N);
    A[0] = B[0] = C[0] = D[0] = 0ll;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &a);
        A[i] = a;
        B[i] = a;
    }

    sort(B, B+N+1);
    int j = 0;
    int k = 0;
    for (int i = 1; i <= N; i++) {
        if (j < B[i]) {
            j = B[i];
            k++;
            C[k] = 0;
            D[k] = j;
        }
        C[k]++;
    }

    for (int i = 1; i <= N; i++) {
        C[i] += C[i-1];
    }

    int t = 0;
    int w = 0;
    for (int i = 1; i <= N; i++) {
        long long u = 0;
        while (t < A[i]) {
            t++;
            while (t > D[w]) w++;  
            u += C[N] - C[w-1];
        }
        s[i] = u;
    }

    for (int i = 1; i <= N; i++) {
        printf("%lld\n", s[i]);
    }

    return 0;
}