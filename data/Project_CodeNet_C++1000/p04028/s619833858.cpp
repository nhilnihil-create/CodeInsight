#include<bits/stdc++.h>
#define mul(x,y) (((x)%P*(y))%P)
#define pls(x,y) ((x)%P+(y))%P
using namespace std;
const int N=10040;
const long long P=1e9+7;
long long qpow(long long x,long long k)
{
    long long rt=1,base=x;
    while(k)
    {
        if(k&1)rt=mul(rt,base);
        base=mul(base,base),k>>=1;
    }return rt;
}
long long f[N/2][N/2];
int main()
{
    int n;char str[N];
    scanf("%d",&n);
    scanf("%s",str);int len=strlen(str);
    f[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
        f[i+1][j+1]=pls(2*f[i][j],f[i+1][j+1]),f[i+1][j-1>-1?j-1:0]=pls(f[i][j],f[i+1][j-1>-1?j-1:0]);
    printf("%lld",mul(f[n][len],qpow(qpow(2,len),P-2)));
    return 0;
}
