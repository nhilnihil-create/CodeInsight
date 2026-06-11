// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, A[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &A[i]);
    sort(A, A + n);
    reverse(A, A + n);
    int nw = 0;
    while (nw + 1 < n && nw + 1 < A[nw + 1])
        nw ++;
    int hrz = 1;
    while (A[nw + hrz] > nw)
        hrz ++;
    int vrt = A[nw] - nw;
    if (hrz % 2 == 1 && vrt % 2 == 1)
        return !printf("Second\n");
    return !printf("First\n");
}