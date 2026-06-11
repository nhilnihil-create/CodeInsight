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
const int N = 1e2+5;
int n, c[N], p, q, h, ans = 1;
int main()
{
    n = read(), p = n-1, q = 0;
    for(int i = 1; i <= n; ++i) 
    {
        int d = read(); ++c[d];
        p = min(d, p); q = max(d, q);
    }
    if(c[q] == 1||(c[p] != 1&&!(q&1))||(c[p] != 2&&(q&1))) ans = 0;
    if(p != (q-1)/2+1) ans = 0;
    for(int i = p+1; i < q; ++i) if(c[i] <= 1) ans = 0;
    puts(ans?"Possible":"Impossible");
    return 0;
}