#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
const int mod=1000000007;
long long fac[maxn];

int qpow(long long a,long long b){
	long long ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

int C(int n,int m){
	return (long long)fac[n]*qpow(fac[m],mod-2)%mod*qpow(fac[n-m],mod-2)%mod;
}

int f(int n,int m){
	return C(n+m-2,n-1);
}

int main(){
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	fac[0]=1;
	for(int i=1;i<maxn;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	int ret=0;
	for(int i=1;i<=h-a;i++){
		ret=(ret+(long long)f(i,b)*f(h-i+1,w-b))%mod;
	}
	cout<<ret;
}