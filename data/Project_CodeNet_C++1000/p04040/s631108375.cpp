#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	int k=1,sum=0;
	char c=getchar();
	for(;c<'0' || c>'9';c=getchar()) if(c=='-') k=-1;
	for(;c>='0' && c<='9';c=getchar()) sum=sum*10+c-48;
	return sum*k;
}
int h,w,a,b;
const int p=1e9+7;
ll fac[300000],inv[300000];
ll ans;
inline ll qsm(ll x,ll k)
{
	ll anss=1,base=x;
	while(k)
	{
		if(k&1) anss=(anss*base)%p;
		base=(base*base)%p;
		k>>=1;
	}
	return anss;
}		
inline ll C(int m,int n){
	if(m==n || m==0) return 1;
	return ((fac[n]*inv[m])%p*inv[n-m])%p;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=200001;++i) fac[i]=(fac[i-1]*i)%p;
	h=read(),w=read(),a=read(),b=read();
	inv[200001]=qsm(fac[200001],p-2);
	for(re int i=200000;i>=1;--i) inv[i]=(inv[i+1]*(i+1))%p;
	for(re int i=1;i<=h-a;++i){
		//cout<<b-1<<" "<<i+b-2<<" "<<w-b-1<<" "<<w+h-b-i-1<<endl;
		//cout<<C(1,2)<<endl;
		ans=(ans+(C(b-1,i+b-2)*C(w-b-1,w+h-b-i-1))%p)%p;
	}
	cout<<ans;
	return 0;
}
/*
6 3
2 3
1 2 
1 4 
4 5 
4 6 
0 2 5 1 2 3 
1 5 
1 3 
2 6 
*/