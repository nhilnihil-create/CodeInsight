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
int n;
int64 a, b, c, d;
int main()
{
    n = read()-1, a = read(), b = read(), c = read(), d = read();
    for(int i = 0; i <= n; ++i)
        if(a+c*i-d*(n-i) <= b&&b <= a+d*i-c*(n-i))
            return puts("YES"), 0;            
    puts("NO");
    return 0;
}