#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int _0v0_=1000;
int ma[510][510],n,m,h,w;
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&w);
	if(n%h==0&&m%w==0){printf("No");return 0;}
	printf("Yes\n");
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ma[i][j]=_0v0_;
	for(int i=1;i<=n/h;i++)for(int j=1;j<=m/w;j++)ma[i*h][j*w]=-(h*w-1)*_0v0_-1;
	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",ma[i][j]);printf("\n");}
	return 0;
}