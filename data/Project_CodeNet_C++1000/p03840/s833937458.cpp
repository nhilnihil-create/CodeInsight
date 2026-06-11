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
int64 a, b, c, d, e;
int64 ans;
int main()
{
    a = read(), ans = read(), c = read(), d = read(), e = read();
    if(!a||!d||!e) ans += a/2*2+d/2*2+e/2*2;
    else ans += a+d+e-(a%2 != d%2||a%2 != e%2);
    printf("%lld\n", ans);
    return 0;
}