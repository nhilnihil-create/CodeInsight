#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2005;
const int mod=1e9+7;
int fact[N*N],inv[N*N];
int d[N][N];
int n,k;
void Init()
{
	fact[0]=1;
	for(int i=1;i<=n*k;i++) fact[i]=1ll*fact[i-1]*i%mod;
	inv[1]=1;
	for(int i=2;i<=n*k;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	inv[0]=1;
	for(int i=1;i<=n*k;i++) inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
int C(int x,int y){
    return 1ll*fact[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    scanf("%d%d",&n,&k);
    if(k==1){
        puts("1");
        return 0;
    }
    Init();
    d[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++){
            if(i>0)
                d[i][j]+=d[i-1][j],d[i][j]%=mod;
            if(j>0){
                int x=n*k-i-(j-1)*(k-1)-1;
                d[i][j]+=1ll*d[i][j-1]*C(x,k-2)%mod;
                d[i][j]%=mod;
            }
        }
    int ans=1ll*d[n][n]*fact[n]%mod;
    printf("%d\n",ans);
}
