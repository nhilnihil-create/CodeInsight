#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 120000

LL n,a[N],sum,m,p,num;

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld",a+i);
		sum+=a[i];
	}
	m=n*(n+1)/2;
	if (sum%m!=0){puts("NO"); return 0;}
	num=sum/m;
	a[0]=a[n];
	for (LL i=1;i<=n;++i){
		LL x=a[i]-a[i-1];
		if (num-x<0||(num-x)%n!=0){puts("NO"); return 0;}
		LL t=(num-x)/n;
		p+=t;
	}
	puts(p==num?"YES":"NO");
	
	return 0;
}
			