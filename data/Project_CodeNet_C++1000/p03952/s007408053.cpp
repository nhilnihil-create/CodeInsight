// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5+5;
int n, x, q, ans;
int p[N], vis[N];
int main()
{
    scanf("%d%d", &n, &x);
    if(x == 1||x == 2*n-1) return puts("No"), 0;
    puts("Yes"); 
    p[n] = x, p[n-1] = x == 2?x+1:x-1, p[n+1] = x == 2?x-1:x+1, p[n+2] = x == 2?x+2:x-2;
    vis[x] = vis[x+1] = vis[x-1] = vis[x == 2?x+2:x-2] = 1;
    for(int i = 1, j = 1; i <= 2*n-1; ++i)
    {
        if(p[i]) continue; while(vis[j]) ++j;
        p[i] = j, vis[j] = 1;
    }
    for(int i = 1; i <= 2*n-1; ++i) printf("%d ", p[i]);
    return 0;
}