#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn=8000005;
const int mod=1e9+7;
int n,k,jc[maxn],inv[maxn],f[2005][2005];
int poww(int x,int y){
    int res=1; 
    while(y){
        if(y&1){
        	res=res*x%mod;
        }
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int C(int n,int k){
    return ((jc[n]*inv[k]%mod)*inv[n-k])%mod;
}
signed main(){
    jc[0]=1;
    for(int i=1;i<maxn;i++){
    	jc[i]=jc[i-1]*i%mod;
    } 
    inv[maxn-1]=poww(jc[maxn-1],mod-2);
    for(int i=maxn-2;i>0;i--){
    	inv[i]=(inv[i+1]*(i+1))%mod;
    } 
    inv[0]=1;
    cin>>n>>k;
    if(k==1){
    	cout<<'1';
    	return 0;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=i;j++){
    		f[i][j]=f[i-1][j];
            if(!j) continue;
    		f[i][j]=f[i-1][j]+(((f[i][j-1]*(n-j+1))%mod)*C(n*k-i-(j-1)*(k-1)-1,k-2)%mod)%mod;
    	}
            
    }
    cout<<f[n][n]<<endl;
}