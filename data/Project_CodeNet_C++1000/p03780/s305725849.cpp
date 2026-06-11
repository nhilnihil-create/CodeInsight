#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,i,j,r,f[5010][5010],g[5010][5010],a[5010],ans;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0][0]=1;
	for(i=1;i<=n;i++)
	 for(j=0;j<=m;j++){
	  f[i][j]=f[i-1][j];
	  if(j>=a[i])f[i][j]|=f[i-1][j-a[i]];
  }
  g[n+1][0]=1;
  for(i=n;i;i--)
   for(j=0;j<=m;j++){
   	g[i][j]=g[i+1][j];
   	if(j>=a[i])g[i][j]|=g[i+1][j-a[i]];
   }
     for(i=1;i<=n;i++){
     	r=m;
     	for(j=0;j<=m;j++)if(f[i-1][j]){
     		while(!g[i+1][r]||j+r>=m)r--;
     		if(j+r+a[i]>=m){
     			//printf("%d\n",i);
     			ans++;break;
			 }
		 }
	 }
	printf("%d",n-ans);
}
/*
怎么做都可以吧 
*/