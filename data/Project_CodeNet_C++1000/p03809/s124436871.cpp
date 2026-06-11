#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,x[100010];
vector<int> a[100010];
bool p;
inline L dfs(int i,int j)
{
    if(a[i].size()==1)
      return x[i];
    int k;
    L l=0,u=0,v;
    for(k=0;k<a[i].size();k++)
      if(a[i][k]!=j)
        {
         v=dfs(a[i][k],i);
         l+=v;
         u=max(u,v);
        }
    L w=l-x[i];
    if(w<0 || 2*w>l || w>l-u)
      {
       p=1;
       return 0;
      }
    else
      return l-2*w;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	if(n==2)
	  {
       if(x[1]==x[2])
         printf("YES\n");
       else
         printf("NO\n");
       return 0;
      }
	for(i=1;i<n;i++)
	  {
       scanf("%d%d",&j,&k);
       a[j].push_back(k);
       a[k].push_back(j);
      }
    for(i=1;i<=n;i++)
      if(a[i].size()>1)
        break;
    if(dfs(i,0) || p)
      printf("NO\n");
    else
      printf("YES\n");
	return 0;
}
