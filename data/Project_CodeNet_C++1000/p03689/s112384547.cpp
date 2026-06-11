#include<bits/stdc++.h>
using namespace std;
int n,m,h,w;
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&w);
	if (n%h!=0){
		puts("Yes");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				if (i%h==1)printf("%d ",1000*(h-1)-1);
				else printf("%d ",-1000);
			puts("");
		}
		return 0;
	}
	if (m%w!=0){
		puts("Yes");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				if (j%w==1)printf("%d ",1000*(w-1)-1);
				else printf("%d ",-1000);
			puts("");
		}
		return 0;
	}
	puts("No");
}