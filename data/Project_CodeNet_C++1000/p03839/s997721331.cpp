#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long int64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, k;
int64 f[N], s[N], suf, ans;
int main()
{
    n = read(), k = read();
    for(int i = 1; i <= n; ++i) 
        s[i] = s[i-1]+read(), 
        f[i] = f[i-1]+max(s[i]-s[i-1], 0ll);
    for(int i = n; i >= k; --i) 
        ans = max(f[i-k]+suf+max(s[i]-s[i-k], 0ll), ans),
        suf += max(s[i]-s[i-1], 0ll);
    printf("%lld\n", ans);
    return 0;
}
/* 
6 5
5 -4 -5 -8 -4 4
*/