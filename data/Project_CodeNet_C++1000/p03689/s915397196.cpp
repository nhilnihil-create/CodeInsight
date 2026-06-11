#include <cstdio>
#include <cstring>
#define MAXN 510
#define LL long long

int W,H,w,h;
LL a[MAXN][MAXN];

int main(){
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(w*h==1){
		puts("No");
		return 0;
	}
	LL x=999999999/(h*w-1);
	LL s=0;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++){
			if(i%h || j%w) a[i][j]=x;
			else a[i][j]=-(x*(w*h-1)+1);
			s+=a[i][j];
		}
	if(s<=0) puts("No");
	else{
		puts("Yes");
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++)
				printf("%lld ",a[i][j]);
			puts("");
		}
	}
}
