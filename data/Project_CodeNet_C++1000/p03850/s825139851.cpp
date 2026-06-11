#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL inf=1LL<<60;
LL n,a[100010],f[100010][3];
char op[100010][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d %s",&a[i],op[i]);
    scanf("%d",&a[n]);
    f[1][0]=a[1];f[1][1]=f[1][2]=-inf;
    for(int i=2;i<=n;i++)
        if(op[i-1][0]=='+')
        {
            f[i][0]=max(f[i-1][0],f[i-1][1])+a[i];
            f[i][1]=f[i-1][1]-a[i];
            f[i][2]=f[i-1][2]+a[i];
        }
        else
        {
            f[i][0]=-inf;
            f[i][1]=max(f[i-1][0],f[i-1][1])-a[i];
            f[i][2]=max(f[i-1][1],f[i-1][2])+a[i];
        }
    printf("%lld",max(f[n][0],max(f[n][1],f[n][2])));
    return 0;
}