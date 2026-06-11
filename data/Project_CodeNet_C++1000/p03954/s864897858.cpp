#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=2e5+2,inf=1e9;
int a[N],b[N];
int n,m,i,x,l,r,mid,c,zx,as;
inline void read(int &x)
{
    c=getchar();
    while ((c<48)||(c>57)) c=getchar();
    x=c^48;c=getchar();
    while ((c>=48)&&(c<=57))
    {
        x=x*10+(c^48);
        c=getchar();
    }
}
inline int ab(int x)
{
    if (x>=0) return x;
    return -x;
}
bool pd()
{
    for (i=1;i<=m;i++) b[i]=(a[i]>=mid);zx=inf;
    for (i=2;i<=m;i++) if (b[i]==b[i-1])
    {
        if ((i==n)||(i==n+1)) return b[i];
        x=min(ab(i-n),ab(n-(i-1)));
        if (x<zx)
        {
            zx=x;
            as=b[i];
        }
    }
    if (zx!=inf) return as;
    return b[1];
}
int main()
{
    read(n);m=(n<<1)-1;
    for (i=1;i<=m;i++) read(a[i]);
    l=1;r=m;
    while (l<r)
    {
        mid=l+r+1>>1;
        if (pd()) l=mid; else r=mid-1;
    }
    printf("%d",l);
}