#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
const LL inf=(LL)1e15;
int n,a[N];
char op[N][2];
LL f[N][3];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++) scanf("%d%s",&a[i],op[i]);
    scanf("%d",&a[n]);
    f[1][0]=a[1];f[1][1]=f[1][2]=-inf;
    for (int i=2;i<=n;i++)
        if (op[i-1][0]=='+')
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