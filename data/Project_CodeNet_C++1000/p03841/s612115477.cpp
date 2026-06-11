#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, X[N], C[N], A[N * N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &X[i]);
        if (A[X[i]])
            return !printf("No\n");
        A[X[i]] = i;
    }
    for (int i = 1; i <= n * n; i++)
        if (!A[i])
        {
            int id = -1;
            for (int j = 1; j <= n; j++)
                if (C[j] < j - 1 && i < X[j] && (id == -1 || X[j] < X[id]))
                    id = j;
            if (id == -1)
                for (int j = 1; j <= n; j++)
                    if (C[j] >= j - 1 && C[j] < n - 1 && i > X[j])
                        id = j;
            if (id == -1)
                return !printf("No\n");
            A[i] = id;
            C[A[i]] ++;
        }
    printf("Yes\n");
    for (int i = 1; i <= n * n; i++)
        printf("%d ", A[i]);
    return 0;
}