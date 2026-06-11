#include<iostream>
#define mod 1000000007
using namespace std;

long long jie[1000005];

long long qpow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b%2)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans%mod;
}

void f(){
	jie[0]=1;
	for(int i=1;i<1000001;i++)
		jie[i]=(jie[i-1]*i)%mod;
}

long long c(long long n,long long m){
	long long a=jie[n];
	long long b=(jie[m]*jie[n-m])%mod;
	return (a*qpow(b,mod-2))%mod;
}

int main(){
	f();
	int h,w,a,b,ans=0;
	cin>>h>>w>>a>>b;
	for(int i=b+1;i<=w;i++){
		long long t=(c(h-a+i-2,h-a-1)%mod*c(w-i+a-1,w-i)%mod)%mod;
		ans=(ans+t)%mod;
	}
	
	cout<<ans<<endl;
	
	return 0;
}