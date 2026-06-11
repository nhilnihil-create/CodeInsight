#include "cstdio"
long long n,x,ss;
long long dfs(long long a,long long b){
	if(a%b==0){
		return(a<<1)-b;
	}
	return a/b*b*2+dfs(b,a%b);
}
int main(){
	scanf("%lld%lld",&n,&x);
	if(x>=n-x)printf("%lld\n",n+dfs(x,n-x));
	else printf("%lld\n",n+dfs(n-x,x));
}