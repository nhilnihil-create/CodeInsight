#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,i,j,bl,x,y;
int main(){
	scanf("%d%d%d",&n,&m,&bl);
	for(i=1;i<=n;i++){
	 for(j=1;j<=m;j++){
	 	x=(i+j+m)/bl%2;
	 	y=(i-j+m)/bl%2;
	 	printf("%c","YBGR"[x*2+y]);
	 }
	 puts("");
  }
}