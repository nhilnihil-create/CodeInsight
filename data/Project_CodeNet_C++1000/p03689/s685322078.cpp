#include<cstdio>
#include<algorithm>
using namespace std;
const int N=550;
int i,j,k,H,W,h,w,fg,t;
int a[N][N];
int main() {
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if (H%h==0 && W%w==0) return puts("No"),0;
	puts("Yes");
	if (H%h) {
		for (i=1;i<=H;i++) {
			for (j=1;j<=W;j++) {
				if (i%h==0) t=-1000000*(h-1);
				else t=999999;
				printf("%d ",t);
			}
			puts("");
		}
	}
	else {
		for (i=1;i<=H;i++) {
			for (j=1;j<=W;j++) {
				if (j%w==0) t=-1000000*(w-1);
				else t=999999;
				printf("%d ",t);
			}
			puts("");
		}
	}
}