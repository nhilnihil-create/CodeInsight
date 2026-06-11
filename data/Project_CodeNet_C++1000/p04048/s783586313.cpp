#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
ll n,x,ans,x1,x2;

int main(){
	scanf("%lld%lld",&n,&x);
	ans=n;
	x1=x,x2=n-x;
	while(1){
		if(x1<x2) swap(x1,x2);
		if(!x2) break;
		if(x1%x2==0) ans-=x2;
		ans+=x2*(x1/x2)*2;
		x1-=x2*(x1/x2);
	}
	printf("%lld\n",ans);
	return 0;
} 