#include <bits/stdc++.h>

using namespace std;


int A[200005];
int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) scanf("%d", A + i);

    int maxP = 0;
    int minV = A[0];
    for (int i = 0; i < n; ++i) {
        maxP = max(maxP, A[i] - minV);
        minV = min(minV, A[i]);
    }

    minV = A[0];
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] - minV == maxP) res++;
        minV = min(minV, A[i]);
    }
    if (n == 1) res = 0;

    printf("%d\n", res);

    return 0;
}
