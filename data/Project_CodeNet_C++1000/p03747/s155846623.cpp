// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, L, T, Cnt, X[N], W[N], A[N];
int main()
{
    scanf("%d%d%d", &n, &L, &T);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d%d", &X[i], &W[i]);
        if (W[i] == 1)
            A[i] = (X[i] + T) % L, Cnt = (Cnt + max((T - (L - X[i]) + L) / L, 0)) % n;
        else
            A[i] = (X[i] - T % L + L) % L, Cnt = (Cnt - max((T - X[i] - 1 + L) / L, 0) + n) % n;
    }
    sort(A, A + n);
    for (int i = 0; i < n; i ++)
        A[i + n] = A[i];
    for (int i = Cnt; i < n + Cnt; i ++)
        printf("%d\n", A[i]);
    return 0;
}