#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define N 3010
#define mo 1000000007ll
ll jc[N*N],ijc[N*N],f[N][N];
int n,k;
ll qp(ll x,ll y){
	ll r=1;
	for(;y;y>>=1,x=x*x%mo)
		if(y&1)r=r*x%mo;
	return r;
}
ll c(ll y,ll x){return jc[y]*ijc[x]%mo*ijc[y-x]%mo;}
signed main(){
	jc[0]=ijc[0]=1;
	for(ll i=1;i<N*N;i++)jc[i]=jc[i-1]*i%mo;
	ijc[N*N-1]=qp(jc[N*N-1],mo-2);
	for(ll i=N*N-2;i;i--)ijc[i]=ijc[i+1]*(i+1ll)%mo;
	cin>>n>>k;
	if(k==1){
		puts("1");
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%mo*c(n*k-i-(j-1)*(k-1)-1,k-2)%mo)%mo;
		}
	cout<<f[n][n];
}