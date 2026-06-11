// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 309;
int n, Mx, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n + n; i ++)
        scanf("%d", &A[i]);
    sort(A, A + n + n);
    for (int i = 0; i < n + n; i += 2)
        Mx += A[i];
    return !printf("%d\n", Mx);
}