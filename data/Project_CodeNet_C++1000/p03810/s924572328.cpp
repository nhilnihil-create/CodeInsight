#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long int64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, a[N], c[2], p, s, d;
int gcd(int a, int b) { return b?gcd(b, a%b):a; }
int simulate()
{
    c[0] = c[1] = 0;
    for(int i = 1; i <= n; ++i) ++c[a[i]&1];
    if(c[0]&1) return 1;
    if((~c[0]&1)&&c[1] >= 2) return 0;
    for(p = 1; p <= n&&(~a[p]&1); ++p);
    if(a[p] == 1)
    {
        for(int i = 1; i <= n; ++i) s ^= (a[i]-1)&1;
        return s;
    }
    --a[p], d = a[1]; 
    for(int i = 2; i <= n; ++i) d = gcd(d, a[i]);
    for(int i = 1; i <= n; ++i) a[i] /= d;
    return simulate()^1;
}
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    puts(simulate()?"First":"Second");
    return 0;
}