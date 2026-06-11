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
int n, c[N], pos[N], ans[N*N];
pair<int, int> p[N];
int main()
{
    n = read();
    for(int i = 1, x; i <= n; ++i) pos[i] = read(), p[i] = make_pair(pos[i], i);
    sort(p+1, p+1+n);
    for(int i = 1; i <= n; ++i) c[i] = p[i].second-1, pos[p[i].second] = i;
    for(int i = 1, j = 1; i <= n; ++i)
    {
        int l = p[i-1].first+1, r = p[i].first;
        for(int k = l; k < r; ++k) 
        {
            while(!c[j]&&j <= n) ++j; if(j == n+1) break;
            ans[k] = p[j].second; --c[j];
        }
        ans[r] = p[i].second;
    }
    for(int i = 1; i <= n*n; ++i) ++c[pos[ans[i]]];
    for(int i = 1, j = 1; i <= n; ++i)
    {
        int l = p[i-1].first+1, r = p[i].first;
        for(int k = l; k <= r; ++k) 
        {
            if(ans[k]) continue;
            while(c[j] == n&&j <= n) ++j; if(j == n+1) break;
            ans[k] = p[j].second; ++c[j];
        }
        if(i < n) continue;
        for(int k = p[n].first+1; k <= n*n; ++k)
        {
            if(ans[k]) continue;
            while(c[j] == n&&j <= n) ++j; if(j == n+1) break;
            ans[k] = p[j].second; ++c[j];
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for(int j = 1; j <= p[i].first; ++j) cnt += p[i].second == ans[j];
        if(cnt != p[i].second) return puts("No"), 0;
    }       
    puts("Yes");
    for(int i = 1; i <= n*n; ++i) printf("%d ", ans[i]);
    return 0;
}

/* 
1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 0 0 0 0 0 0 0 0 0 0
*/