#include<cstdio>
int n,f[1000007],P=1000000007;
int main()
{
    scanf("%d",&n),f[n]=n,f[n-1]=1ll*n*n%P;
    for(int i=n-2,s=0;i>0;--i) (s+=f[i+3])%=P,f[i]=(f[i+1]+1ll*(n-1)*(n-1)+s+i+1)%P;
    printf("%d",f[1]);
}
