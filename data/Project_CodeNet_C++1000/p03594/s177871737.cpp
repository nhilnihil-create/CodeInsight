#include<cstdio>
int n,m,d,i,j,x,y,o;
const char p[]={'R','Y','G','B'};
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			x=i+j+m;
			y=i-j+m;
			o=x/d%2*2+y/d%2;
			printf("%c",p[o]);
		}
		printf("\n");
	}
	//while(1);
}
