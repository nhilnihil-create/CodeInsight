#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,a,b,x[510][510];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(n%a==0 && m%b==0)
	  {
	   printf("No\n");
	   return 0;
	  }
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    x[i][j]=1000;
	if(n%a)
	  for(i=a;i<=n;i+=a)
	    for(j=1;j<=m;j++)
	      x[i][j]*=-a+1;
	else
	  for(i=1;i<=n;i++)
	    for(j=b;j<=m;j+=b)
	      x[i][j]*=-b+1;
	for(i=1;i<=n;i+=a)
	  for(j=1;j<=m;j+=b)
	    x[i][j]--;
	printf("Yes\n");
	for(i=1;i<=n;i++)
	  {
	   for(j=1;j<=m;j++)
	     printf("%d ",x[i][j]);
	   printf("\n");
	  }
	return 0;
}
