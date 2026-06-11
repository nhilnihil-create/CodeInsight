#include<iostream>
#include<cstdio>
using namespace std;
int n,x,cnt,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		if (x==i) ++cnt;else ans+=(cnt+1)>>1,cnt=0;
	}
	ans+=(cnt+1)>>1;
	printf("%d",ans);
	return 0;
}