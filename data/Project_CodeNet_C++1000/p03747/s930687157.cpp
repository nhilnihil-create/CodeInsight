#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 10;
int x[maxn], pos[maxn], w[maxn];
int l, p, s, t, n, m;
ll exc;

inline int read()
{
    int w = 0, t = 1; char ch = getchar();
    while (ch > '9' || ch < '0') {if (ch == '-') t = - 1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { w = (w << 3) + (w << 1) + (ch ^ 48); ch = getchar();}
    return w * t;
}

int main()
{
    n = read(), l = read(), t = read();
    for( int i = 1; i <= n; i++)
        x[i] = read(),
        w[i] = read();
    for(int i = 1; i <= n; i++)
    {
        if (w[i] == 2) w[i] = -1;
        p = x[i] + w[i] * t;
        if (p > 0)
            (exc += p / l) %= n;
        else if (p < 0)
            (exc += (p + 1) / l - 1) %= n;
        pos[i] = (p % l + l) % l;
    }
    std::sort(pos + 1, pos + n + 1);
    exc = (exc + n) % n; 
    exc ++;
    for(int i = exc; i <= n; i++)
        printf("%d\n", pos[i]);
    for(int i = 1; i < exc; i++) printf("%d\n", pos[i]);
}
