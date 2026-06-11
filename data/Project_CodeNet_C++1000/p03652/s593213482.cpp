#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read(int f = 1, int x  = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 3e2+5;
int n, m, a[N][N], del[N], c[N], p[N], ans;
int main()
{
    ans = n = read(), m = read(), del[0] = 1;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) 
            a[i][j] = read();
    for(int maxw = 0; m; maxw = 0)
    {
        memset(c+1, 0, sizeof(int)*m);
        for(int i = 1; i <= n; ++i) 
        {
            for( ; del[a[i][p[i]]]&&p[i] <= m; ++p[i]);
            ++c[a[i][p[i]]]; if(p[i] > m) return printf("%d\n", ans), 0;
        }
        for(int i = 1; i <= m; ++i) maxw = max(maxw, c[i]);
        ans = min(ans, maxw);
        for(int i = 1; i <= m; ++i) if(maxw == c[i]) del[i] = 1;
    }
    return 0;
}