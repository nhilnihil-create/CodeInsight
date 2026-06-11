#include<bits/stdc++.h>
#define ll long long
using namespace std;
int H,W,n,m,i,j,x;
int main(){
	scanf("%d%d%d%d",&H,&W,&n,&m);
	if(H%n==0&&W%m==0)return puts("No"),0;
	puts("Yes");
	x=(H/n)*(W/m)+1;
	for(i=1;i<=H;i++){
		for(j=1;j<=W;j++)if(i%n==0&&j%m==0)printf("%d ",-x*(n*m-1)-1);
		 else printf("%d ",x);
		puts("");
	}
}