#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
#define mul(x,y) ((long long)(x)*(y)%mod)
const int N=5010;
int f[N],inv[N],invf[N],d[N],pp[N];char buf[N];
int bin(int n,int r){
	return mul(f[n],mul(invf[r],invf[n-r]));
}
int main(){
	inv[1]=1;
	for(int i=2;i<N;i++)inv[i]=mul(mod-mod/i,inv[mod%i]);
	f[0]=invf[0]=1;
	for(int i=1;i<N;i++){
		f[i]=mul(i,f[i-1]);
		invf[i]=mul(invf[i-1],inv[i]);
	}
	pp[0]=1;
	for(int i=1;i<N;i++)pp[i]=mul(pp[i-1],2);
	d[0]=1;
	for(int i=1;i<N;i++){
		d[i]=d[i-1];
		for(int k=2;k<=i;k+=2){
			d[i]+=mul(d[i-k],mul(pp[k/2],mul(inv[k/2],bin(k-2,k/2-1))));
			if(d[i]>=mod)d[i]-=mod;
		}
	}
	int n;scanf("%d",&n);scanf("%s",buf);int m=strlen(buf);
	int ans=0;
	for(int k=0;k<=(n-m)/2;k++){
		int x=1;
		x=mul(x,m);
		x=mul(x,inv[m+k]);
		x=mul(x,bin(m+2*k-1,k));
		x=mul(x,pp[k]);
		x=mul(x,d[n-m-k-k]);
		ans+=x;
		if(ans>=mod)ans-=mod;
	}
	printf("%d\n",ans);
}