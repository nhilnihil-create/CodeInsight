#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int ans=1,m=0,c=0;
	for(int i=1;i<=n;i++){
		c=__builtin_ctz(i);
		if(c>m){
			ans=i;
			m=c;
		}
	}
	printf("%d",ans);
}
