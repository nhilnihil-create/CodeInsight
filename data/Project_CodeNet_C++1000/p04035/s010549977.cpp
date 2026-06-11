#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, L, id, A[N];
int main()
{
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    for (int i = 1; i < n; i ++)
        if (A[i] + A[i + 1] >= L)
            id = i;
    if (!id)
        return !printf("Impossible\n");
    printf("Possible\n");
    for (int i = n - 1; i > id; i --)
        printf("%d\n", i);
    for (int i = 1; i <= id; i ++)
        printf("%d\n", i);
    return 0;
}