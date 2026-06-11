// n/w * m/h 个特殊点
// 设特殊点权值为x，其他点为y,那么满足：
// x = y * (1 - w*h) - 1
// n/w * m/h * (x-y) + y * n * m > 0 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

int a[N][N],n,m,w,h,v;
ll sum=0;

int main(){
	scanf("%d%d%d%d",&n,&m,&w,&h),v=1000*(1-w*h)-1;
	for(int i=w;i<=n;i+=w)
		for(int j=h;j<=m;j+=h) a[i][j]=v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		    if(a[i][j]) sum+=(ll)a[i][j];
	        else sum+=(ll)1000,a[i][j]+=1000;

	if(sum<=0){ puts("No"); return 0;}

	puts("Yes");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
		puts("");
	}
	
	return 0;
}