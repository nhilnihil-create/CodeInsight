#include<cstdio>
using namespace std;
int h,w,d;
char c[2][2]={{'R','Y'},{'G','B'}};

int main(void){
	register int i,j,x,y;
	scanf("%d%d%d",&h,&w,&d);
	for(i=1;i<=h;++i,putchar('\n'))
		for(j=1;j<=w;++j){
			x=i+j+1001,y=i-j+1001;
			x/=d,y/=d,x&=1,y&=1;
			printf("%c",c[x][y]);
		}
	return 0;
}