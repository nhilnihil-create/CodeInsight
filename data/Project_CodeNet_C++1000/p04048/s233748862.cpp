#include <algorithm>
#include <cctype>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long int64;
inline int64 read(int64 f = 1, int64 x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
int64 n, x;
int main()
{
    n = read(), x = read(); 
    printf("%lld\n", 3*(n-__gcd(n, x)));
    return 0;
}