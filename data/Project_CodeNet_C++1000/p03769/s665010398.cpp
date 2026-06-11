#include<bits/stdc++.h>
#define L long long
using namespace std;
int m,x[210],p;
L n;
inline void dfs(L n)
{
    if(n==1)
      return;
    if(n&1)
      {
       int u=++p;
       dfs(n-1);
       x[++m]=u;
      }
    else
      {
       x[++m]=++p;
       dfs(n/2);
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	cin>>n;
	n++;
	dfs(n);
	printf("%d\n",2*m);
	for(i=1;i<=m;i++)
	  printf("%d ",i);
	for(i=1;i<=m;i++)
	  printf("%d ",x[i]);
	return 0;
}
