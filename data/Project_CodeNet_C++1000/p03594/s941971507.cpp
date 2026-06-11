#include <iostream>
#include <cstdio>
#define N 3002
using namespace std;
int n,m,k,l,r,u,d,i,j,ans[N][N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int x=i+j,y=i-j+m-1;
			l=min(l,y);r=max(r,y);
			u=min(u,x);d=max(d,x);
		}
	}
	for(i=u;i<=d;i++){
		for(j=l;j<=r;j++){
			int x=i+1,y=j+1;
			if(((x-1)/k)%2==0){
				if(((y-1)/k)%2==0) ans[i][j]=1;
				else ans[i][j]=2;
			}
			else{
				if(((y-1)/k)%2==0) ans[i][j]=3;
				else ans[i][j]=4;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int x=i+j,y=i-j+m-1;
			if(ans[x][y]==1) printf("R");
			else if(ans[x][y]==2) printf("Y");
			else if(ans[x][y]==3) printf("G");
			else printf("B");
		}
		puts("");
	}
	return 0;
}
