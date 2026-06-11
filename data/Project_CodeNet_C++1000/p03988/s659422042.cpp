#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
#define INF 99999999
int n, mn = INF, mx, cnt, a[maxn], b[maxn];

int read()
{
    int x = 0, k = 1;
    char c; c = getchar();
    while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c= getchar();
    return x * k;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i ++)
    {
        a[i] = read();
        mn = min(mn, a[i]), mx = max(mx, a[i]);
    }
    for(int i = 1; i <= n; i ++)
        if(a[i] == mn) cnt ++;
    if(cnt != (mx & 1) + 1) { printf("Impossible\n"); return 0; }
    for(int i = 1; i <= n; i ++) b[a[i]] ++;
    for(int i = mn + 1; i <= mx; i ++)
        if(b[i] < 2) { printf("Impossible\n"); return 0; }
    printf("Possible\n");
    return 0;
} 