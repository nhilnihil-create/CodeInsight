#include<cstdio>
long long ans[51],k,tmp,to;
int main(){
//	freopen("ex.in","r",stdin);
	scanf("%lld",&k);tmp=k/50;to=k%50;
	for(int i=1;i<=50;++i) ans[i]=i-1+tmp;
	for(int i=50;i&&to;--i){
		ans[i]++;
		to--;
	}
	puts("50");
	for(int i=1;i<50;++i) printf("%lld ",ans[i]);printf("%lld",ans[50]);
	return 0;
}