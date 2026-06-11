#include<iostream>
#include<stdio.h>
#include<string.h>
#define P 1000000007
using namespace std;
int n;
long long f[1200000],ans,sum;
long long power(long long x,int k){
	long long ans=1;
	while(k){
		if(k&1)(ans*=x)%=P;
		(x*=x)%=P;
		k>>=1;
	}
	return ans;
}
long long get(long long x){
	if(x>=3)return n-x+2;
	return n-x+1;
}
long long cal(long long x){
	if(x>=2)return (1LL*(n-1)*(n-1)%P+get(x))%P;
	return n;
}
int main(){
	scanf("%d",&n);
	f[0]=1;
	f[1]=1;
	if(n==1){
		printf("1\n");
		return 0;
	}
	ans+=cal(n)*f[0]+cal(n-1)*f[1];
	sum=2;
	ans%=P; 
	for(int i=2;i<n;i++){
		f[i]=(sum-f[i-2]+P)%P;
		ans+=f[i]*cal(n-i)%P;
		ans%=P;
		(sum+=f[i])%=P;
	}
	printf("%lld",ans);
}