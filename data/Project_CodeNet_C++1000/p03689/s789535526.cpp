#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;


int a[1000];
void f(int H,int h){
	int c=H/h+1,d=-1;
	rep(i,H){
		if(i%h==h-1){
			a[i]=d;
			c--;d--;
		}
		else{
			a[i]=c;
		}
	}
}
int ans[1000][1000];
int main(){
	int H,W,h,w;scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h==0&&W%w==0){
		puts("No");return 0;
	}
	puts("Yes");
	if(H%h){
		f(H,h);
		rep(i,W)rep(j,H){
			ans[j][i]=a[j]-(j?a[j-1]:0);
		}
	}
	else{
		f(W,w);
		rep(i,H)rep(j,W){
			ans[i][j]=a[j]-(j?a[j-1]:0);
		}
	}
	rep(i,H){
		rep(j,W){
			if(j)printf(" ");
			printf("%d",ans[i][j]);
		}
		puts("");
	}
}