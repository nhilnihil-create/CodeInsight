#include <cstdio>
#include <cstring>
typedef long long ll;

int n,l,f[2][5005],Ans=1;
char s[5005];
const int p=1000000007,I2=(p+1)>>1;

int main()
{
    scanf("%d%s",&n,s+1),l=strlen(s+1),f[1][0]=1;
    for(int i=1;i<=l;++i)Ans=(ll)Ans*I2%p;
    for(int i=1;i<=n;++i)
    {
        memcpy(f[0],f[1],sizeof f[0]),memset(f[1],0,sizeof f[1]);
        for(int j=0;j<=i;++j)
        {
            if(j)f[1][j]=(f[0][j-1]<<1)%p;
            if(!j)f[1][0]=(f[1][0]+f[0][0])%p;
            f[1][j]=(f[1][j]+f[0][j+1])%p;
        }
    }
    printf("%d\n",int((ll)Ans*f[1][l]%p));
    return 0;
}