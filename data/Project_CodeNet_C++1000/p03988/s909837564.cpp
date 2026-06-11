#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;
int a[MAXN], b[MAXN];
int n, mx = 0;
template <class T>
inline void _read(T &x)
{
    x = 0;
    char t = getchar();
    while (!isdigit(t) && t != '-') t = getchar(); 
    if (t == '-')
    {
        _read(x);
        x *= -1;
        return ;
    }
    while (isdigit(t))
    {
        x = x * 10 + t - '0';
        t = getchar();
    }
}
int main()
{
    _read(n);
    for (int i = 1; i <= n; ++i) _read(a[i]), mx = max(mx, a[i]), ++b[a[i]];
    if(mx & 1)
    {
        for(int i = mx; i >= (mx + 1) / 2; --i)
            if(b[i] < 2)
            {
                puts("Impossible");
                return 0;
            }
        for(int i = 1; i < (mx + 1) / 2; ++i)
            if(b[i])
            {
                puts("Impossible");
                return 0;
            }
        if(b[(mx + 1) / 2] > 2)
        {
            puts("Impossible");
            return 0;
        }
    }
    else
    {
        for(int i = mx; i > mx / 2; --i)
            if(b[i] < 2)
            {
                puts("Impossible");
                return 0;
            }
        for(int i = 1; i < mx / 2; ++i)
            if(b[i])
            {
                puts("Impossible");
                return 0;
            }
        if(b[mx / 2] != 1)
        {
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    return 0;
}