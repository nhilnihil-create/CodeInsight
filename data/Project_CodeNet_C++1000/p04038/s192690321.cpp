#include<bits/stdc++.h>
using namespace std;
const int N=2010,p=1e9+7;
int mpow(int a,int n){
    int ret=1;
    while(n){
        if(n&1)ret=1ll*ret*a%p;
        a=1ll*a*a%p;
        n/=2;
	}
	return ret;
}
int fac[N*N],inv[N*N];
int C(int n,int m){
    return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int n,m;
int f[2010][2010];
int main(){
    fac[0]=1;
    for(int i=1;i<N*N;++i)fac[i]=1ll*fac[i-1]*i%p;
    inv[N*N-1]=mpow(fac[N*N-1],p-2);
    for(int i=N*N-2;i;--i)inv[i]=1ll*inv[i+1]*(i+1)%p;
    inv[0]=1;
    cin>>n>>m;
    if(m==1){
        cout<<1<<endl;
        return 0;
	}
    f[0][0]=1;
    for(int i=1;i<=n;++i){
    	for(int j=n;j>=0;--j){
    	    if(j<=i&&j){
    	        f[i][j]=(f[i][j]+1ll*f[i-1][j-1]*C(m*i-j-1,m-2)%p)%p;
			}
			f[i][j]+=f[i][j+1];
			f[i][j]%=p;
		}
	}
	f[n][0]=1ll*f[n][0]*fac[n]%p;
	cout<<f[n][0];
}