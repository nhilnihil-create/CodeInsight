#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN=2005;
const int MAXM=4000005;
const int MOD=1e9+7;

ll n,k;
ll d[MAXN][MAXN],fac[MAXM],inv[MAXM];

void Init(){
    fac[0]=1;
    for(int i=1;i<MAXM;i++) fac[i]=fac[i-1]*i%MOD;
    inv[1]=1;
    for(int i=2;i<MAXM;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    inv[0]=1;
    for(int i=1;i<MAXM;i++) inv[i]=inv[i]*inv[i-1]%MOD;
}

ll C(ll x,ll y){
    if(x<y) return 0;
    return (fac[x]*inv[y]%MOD)*inv[x-y]%MOD;
}

int main(){

    Init();
    scanf("%lld%lld",&n,&k);
    if(k==1) return puts("1"),0;
    d[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++){
            if(i) d[i][j]=d[i-1][j];
            if(j) d[i][j]=(d[i][j]+d[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2)%MOD)%MOD;
        }
    d[n][n]=(d[n][n]*fac[n])%MOD;
    printf("%lld",d[n][n]);

    fclose(stdin);
    fclose(stdout);
}
