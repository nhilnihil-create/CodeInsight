#define yuki(x, y) for(int i = x, __yuki = y; i < __yuki; ++i)
#define yukj(x, y) for(int j = x, __yukj = y; j < __yukj; ++j)
#define yukii(x, y) for(int i = x; __yukii = y; i <= __yukii; ++i)
#define yukji(x, y) for(int j = x; __yukji = y; j <= __yukji; ++j)
#define yuk(x, y, z) for(int x = y, __yuk = z; x < __yuk; ++x)
#define yui(x, y, z) for(int x = y, __yui = z; x >= __yui; --x)
#define sclr(x) memset(x, 0, sizeof(x))
#define sclr1(x) memset(x, -1, sizeof(x))
#define scl(x, y) memset(x, y, sizeof(x))
#define ft first
#define sc second
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lol;
int n, a[100100];
bool op[100100];
void sread()
{
    scanf("%d", &n);
    char s[10];
    yuki(0, n-1)
    {
	scanf("%d%s", a+i, s);
	op[i+1] = s[0] == '-';
    }
    scanf("%d", a+n-1);
}
int main(int argc, char **argv)
{
    sread();
    lol maxs = 0, mins = 0, curs = 0, t;
    yui(i, n-1, 1)
	if(op[i])
	{
	    t = maxs;
	    maxs = max(-a[i]+curs+maxs, -(a[i]+curs+mins));
	    mins = min(-(a[i]+curs)+mins, -(a[i]+curs+t));
	    curs = 0;
	}else
	    curs += a[i];
    printf("%lld\n", maxs+curs+a[0]);
    return 0;
}
