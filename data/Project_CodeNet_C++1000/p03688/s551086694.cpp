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
int n, f[2], g[2];
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) 
    {
        int x = read();
        if(!f[0]||f[0] == x) f[0] = x, ++f[1];
        else if(!g[0]||g[0] == x) g[0] = x, ++g[1];
    }
    if(f[0] > g[0]) swap(f[0], g[0]), swap(f[1], g[1]);
    if(!f[0]&&g[0] == n-1&&g[1] == n) puts("Yes");
    else if(f[1]+g[1] != n||(f[0]+1 != g[0]&&f[0])||f[1]+(g[0]-f[1])*2 > n||f[1]+1 > g[0]) puts("No");
    else puts("Yes");
    return 0;
}
/*
3
2 2 2
*/