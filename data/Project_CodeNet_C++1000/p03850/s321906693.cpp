#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,k;char c;long long f0,f1,f2;
int main(){
	scanf("%d%d",&n,&f0);
	for (f1=f2=-1e18,n--;n--;){
		scanf(" %c%d",&c,&k);
		if (c=='-') k=-k;
		long long v0=f0+k,v1=f1-k,v2=f2+k;
		f0=max(v0,max(v1,v2));
		if (c=='+') f1=max(v1,v2),f2=v2;
		else f1=max(v0,max(v1,v2)),f2=max(v1,v2);
	}
	printf("%lld",f0);
}
