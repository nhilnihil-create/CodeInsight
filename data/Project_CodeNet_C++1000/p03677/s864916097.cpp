#include<bits/stdc++.h>
using namespace std;
int N, M;
long long arr0[1010101];
long long arr1[1010101];
long long arr2[1010101];
long long ans = 0;
void add(int x, int y)
{
    if(y<x) y += M;
    if(y-x >= 2)
    {
        arr2[x+2] += 1;
        arr2[y+1] += x - y;
        arr2[y+2] += y - x - 1;
    }
    ans += y - x;
}
int main()
{
    scanf("%d%d", &N, &M);
    int ai; scanf("%d", &ai);
    for(int i=1; i<N; ++i)
    {
        int t; scanf("%d", &t); add(ai, t);
        ai = t;
    }
    for(int i=1; i<=2*M; ++i)
    {
        arr1[i] = arr1[i-1] + arr2[i];
        arr0[i] = arr0[i-1] + arr1[i];
    }
    long long maxv = 0;
    for(int i=1; i<=M; ++i)
        maxv = max(maxv, arr0[i] + arr0[i+M]);
    printf("%lld\n", ans - maxv);
}















