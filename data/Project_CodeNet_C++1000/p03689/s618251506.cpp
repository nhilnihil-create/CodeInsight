#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 5e2+5;
int n, m, w, h, f, ans[N][N];
int main()
{
    n = read(), m = read(), w = read(), h = read();
    if(n%w == 0&&m%h == 0) return puts("No"), 0;
    else if(n%w == 0) swap(n, m), swap(w, h), f = 1;
    for(int i = 1; i <= n; i += w) ans[i][(m/h)*h] = (n/w)*(m/h)+1;
    for(int i = w; i <= n; i += w) ans[i][(m/h)*h] = -(n/w)*(m/h)-2;
    for(int i = w; i <= n; i += w)
        for(int j = h; j+h <= m; j += h)
            ans[i][j] = -1;
    puts("Yes");
    if(!f)
        for(int i = 1; i <= n; ++i, puts(""))
            for(int j = 1; j <= m; ++j)
                printf("%d ", ans[i][j]);
    else 
        for(int i = 1; i <= m; ++i, puts(""))
            for(int j = 1; j <= n; ++j)
                printf("%d ", ans[j][i]);
    return 0;
}
/*
4 3 2 2
*/