#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
long long n,len,f[5005][5005]={0};
char s[5005];
long long qpow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
	return res;
}
int main(){
    scanf("%d%s",&n,s);
    len=strlen(s);
    f[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++){
            f[i+1][j+1]=(2*f[i][j]%mod+f[i+1][j+1])%mod;
            if(j>=1) f[i+1][j-1]=(f[i][j]+f[i+1][j-1])%mod;
            else f[i+1][0]=(f[i][j]+f[i+1][0])%mod;
        }
    long long ans=qpow(qpow(2,len),mod-2)*f[n][len]%mod;
    printf("%d\n",ans);
    return 0;
}