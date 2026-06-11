#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int n,m,h,w,a[505][505];
ll sum[505][505];
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&w);
	if(h==1&&w==1) return puts("No"),0;
	const int inf=1e9;
	for(int i=h;i<=n;i+=h){
		for(int p=w;p<=m;p+=w) a[i][p]=-inf;
	}
	for(int i=1;i<=n;i+=h){
		for(int p=1;p<=m;p+=w) a[i][p]=inf-1;
	}
	for(int i=1;i<=n;i++){
		for(int p=1;p<=m;p++) sum[i][p]=sum[i-1][p]+sum[i][p-1]-sum[i-1][p-1]+a[i][p];
	}
	if(sum[n][m]<=0) puts("No");
	else{
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(int p=1;p<=m;p++) printf(p==m?"%d\n":"%d ",a[i][p]);
		}
	}
	return 0;
}