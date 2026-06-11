#include<bits/stdc++.h>
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=305;
int n;
LL mp[N][N],f[N][N];
LL sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    scanf("%lld",&mp[i][j]);
	memcpy(f,mp,sizeof(f));
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    if(f[i][j]!=mp[i][j])
	      {puts("-1");return 0;}
//	for(int i=1;i<=n;i++)
//	  for(int j=i+1;j<=n;j++)
//	    sum+=f[i][j];
//	cout<<sum<<endl;
	
	  for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++){
	    	bool vis=1;
	    	for(int k=1;k<=n;k++)
	        if(k!=i&&k!=j)
	         if(f[i][j]==f[i][k]+f[k][j])
	          {vis=0;break;}
	        if(vis) sum+=f[i][j];
	    }
	      
	cout<<sum<<endl;
	return 0;
}
