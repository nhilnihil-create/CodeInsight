#include<bits/stdc++.h>
#define ll long long
#define rint register int
using namespace std;
const int N=1e5+50;
int n,a[N<<1],Q,f[35][N],L;
int main()
{
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
  scanf("%d",&L);
  for(int i=1;i<=n;i++)
    {
        int x=upper_bound(a+i+1,a+n+1,a[i]+L)-a-1;
        f[0][i]=x;
    }
  for(int j=1;j<=30;j++)
    for(int i=1;i<=n;i++)
      f[j][i]=f[j-1][f[j-1][i]];
  scanf("%d",&Q);
  while(Q--)
  {
  	int l,r,ans=0;
  	scanf("%d%d",&l,&r);
  	if(l>r) swap(l,r); 
  	for(int i=30;i>=0;i--)
  	{  
	  if(f[i][l]<r) l=f[i][l],ans+=(1<<i);	
  	}
  	printf("%d\n",ans+1);
  }
  return 0;
}
