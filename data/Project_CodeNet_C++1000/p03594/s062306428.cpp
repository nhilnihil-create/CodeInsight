#include<cstdio>
#include<cstring>
using namespace std;
int a[510][510];
int Abs(int x){
	return x>0?x:-x;
}
int main(){
//	freopen("A.in","r",stdin);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(((i+j)/k)&1)
				a[i][j]+=2;
			if(((m-j+i)/k)&1)
				a[i][j]+=1;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0) printf("Y");
			if(a[i][j]==1) printf("G");
			if(a[i][j]==2) printf("B");
			if(a[i][j]==3) printf("R");
		}
		printf("\n");
	}
	return 0;
}
