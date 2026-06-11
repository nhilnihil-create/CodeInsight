#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,x[100010],f[100010],u,v,w,p;
vector<int> a[100010];
inline void dfs(int i)
{
    int j;
    for(j=0;j<a[i].size();j++)
      if(!f[a[i][j]])
        {
         f[a[i][j]]=f[i]^1;
         dfs(a[i][j]);
        }
      else if(f[a[i][j]]==f[i])
        p=1;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
       scanf("%d%d",&j,&k);
       a[j].push_back(k);
       a[k].push_back(j);
      }
    for(i=1;i<=n;i++)
      if(!f[i])
        if(!a[i].size())
          w++;
        else
          {
           f[i]=2;
           p=0;
           dfs(i);
           if(p)
             v++;
           else
             u++;
          }
    printf("%lld\n",(L)n*n-(L)(n-w)*(n-w)+(L)(u+v)*(u+v)+(L)u*u);
	return 0;
}
