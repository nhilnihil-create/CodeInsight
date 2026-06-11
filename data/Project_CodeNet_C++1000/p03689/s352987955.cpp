#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,h,w,i,j,d,a[501][501];
ll ans;
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&w);
	d=(1-h*w)*1000-1;
	for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++){
	  if(i%h==0&&j%w==0)a[i][j]=d;
	  else a[i][j]=1000;
	  ans+=a[i][j];
  }
  if(ans<=0)return puts("No"),0;
  puts("Yes");
  for(i=1;i<=n;i++,puts(""))
   for(j=1;j<=m;j++)printf("%d ",a[i][j]);
}
