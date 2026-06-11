#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, A[N], B[N], M[N];
bool Solve(int md)
{
    for (int i = 1; i <= n + n - 1; i++)
        B[i] = (A[i] >= md);
    B[0] = B[n + n] = -1;
    memset(M, 0, sizeof(M));
    for (int i = 1; i <= n + n - 1; i++)
        if (B[i] == B[i - 1] || B[i] == B[i + 1])
            M[i] = 1;
    if (M[n])
        return (B[n]);
    int l = n, r = l;
    while (l && !M[l]) l --;
    while (r < n + n && !M[r]) r ++;
    if (l == 0 && r == n + n)
        return (B[1]);
    if (((r - l) & 1) && n - l > r - n)
        return (B[l + 1]);
    if ((r - l) & 1)
        return (B[r - 1]);
    return (!B[l + 1]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n + n - 1; i++)
        scanf("%d", &A[i]);
    int le = 1, ri = n + n, md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (Solve(md))
            le = md;
        else
            ri = md;
    }
    return !printf("%d\n", le);
}