#include <algorithm>
#include <cstdio>
int main(){
	int n;long long f0,f1,f2;
	scanf("%d%lld",&n,&f0);
	f1=f2=-1e18;
	for (int i=1;i<n;i++){
		char op;int x;
		scanf(" %c%d",&op,&x);
		if (op=='-') f0=f1=std::max(f0-x,f2=f1+x);
		else f0+=x,f1=std::max(f1-x,f2+=x);
	}
	printf("%lld\n",f0);
}