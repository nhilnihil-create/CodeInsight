#include<cstdio>
long long n,m,ans;
void dfs(long long const &x,long long const &y){
	if(x%y==0){
		ans+=x*2-y;
		return;
	}
	else{
		ans+=(x-x%y)*2;
		dfs(y,x%y);
	}
}
int main(){
	scanf("%lld%lld",&n,&m);
	ans=n;
	n-=m;
	dfs(n>m?n:m,n<m?n:m);
	printf("%lld",ans);
	return 0;
}