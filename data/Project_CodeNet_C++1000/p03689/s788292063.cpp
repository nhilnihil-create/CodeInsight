#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
 
const int N=505;
const int d=500;
 
int n,m,h,w,x,y,v;
int a[N][N];
 
int main(){
	int i,j;
	scanf("%d%d%d%d",&n,&m,&h,&w);
	x=n/h; y=m/w; v=-h*w;
	if (n%h==0&&m%w==0){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (i=1;i<=x;i++)
		for (j=1;j<=y;j++) a[i*h][j*w]=v*d+d-1;
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++)
			if (a[i][j]) printf("%d ",a[i][j]);
		else printf("%d ",d);
		printf("\n");
	}
	return 0;
} 