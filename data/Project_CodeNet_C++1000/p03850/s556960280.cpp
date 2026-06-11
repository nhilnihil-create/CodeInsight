#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
using namespace std;

typedef long long LL;
int n;
LL f[100100][3];

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

int main()
{
    n=getint();
    memset(f,200,sizeof(f)),f[1][0]=getint();
    repu(i,2,n)
    {
        char ch=getchar();
        int x=getint();
        if (ch=='+')
        {
            f[i][0]=max(f[i-1][0]+x,f[i-1][1]-x);
            f[i][1]=max(f[i-1][1]-x,f[i-1][2]+x);
            f[i][2]=f[i-1][2]+x;
        }
        else
        {
            f[i][0]=max(f[i-1][0]-x,f[i-1][1]+x);
            f[i][1]=max(max(f[i-1][0],f[i-1][2])-x,f[i-1][1]+x);
            f[i][2]=max(f[i-1][1]+x,f[i-1][2]-x);
        }
    }
    printf("%lld\n",max(f[n][0],max(f[n][1],f[n][2])));
    return 0;
}