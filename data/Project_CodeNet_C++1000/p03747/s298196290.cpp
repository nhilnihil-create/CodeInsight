// luogu-judger-enable-o2
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, t, p, l;
int a[N];
int main()
{
    n = read(), l = read(), t = read();
    for(int i = 0, d; i < n; ++i) 
    {
        a[i] = read(), d = read();
        if(d == 1) p += (a[i]+t)/l, a[i] = (a[i]+t)%l;
        else p += (a[i]-t)/l, a[i] = (a[i]-t)%l, p -= a[i] < 0, a[i] = (a[i]+l)%l;
    }
    p = (p%n+n)%n, sort(a, a+n);
    for(int i = p; i < n; ++i) printf("%d\n", a[i]);
    for(int i = 0; i < p; ++i) printf("%d\n", a[i]);
    return 0;
}