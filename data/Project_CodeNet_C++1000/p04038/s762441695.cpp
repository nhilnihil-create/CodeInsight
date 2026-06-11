#include<bits/stdc++.h>
using namespace std;

const int N=2010,N2=N*N,mod=1000000007;
typedef long long ll;
int ksm(ll a,int b,int c=1){
	for(;b;b/=2,a=a*a%mod)
		if(b&1)c=c*a%mod;
	return c;
}

int jc[N2],jc2[N2],n,K,f[N][N];

int C(int n,int k){
	if(k<0||n<k)return 0;
	return (ll)jc[n]*jc2[k]%mod*jc2[n-k]%mod;
}

void Init(){
	jc[0]=1;
	for(int i=1;i<N2;++i)jc[i]=(ll)jc[i-1]*i%mod;
	jc2[N2-1]=ksm(jc[N2-1],mod-2);
	for(int i=N2-1;i;--i)jc2[i-1]=(ll)jc2[i]*i%mod;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>K;Init();--K;
	if(!K){
		cout<<1<<'\n';
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)f[i][j]=(f[i-1][j]+(ll)f[i][j-1]*C((n-j+1)*K+n-i-1,K-1))%mod;
	cout<<(ll)f[n][n]*jc[n]%mod<<'\n';
	return 0;
}
