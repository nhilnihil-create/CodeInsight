#include <iostream>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f,maxn=404;
int f[maxn][maxn],a[44],b[44],c[44],m,n,na,nb,sa[44],sb[44];
int main()
{
	int i,j,k,ans=INF;
	cin>>n>>na>>nb;
	memset(f,INF,sizeof(f));
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		sa[i]=sa[i-1]+a[i];
		sb[i]=sb[i-1]+b[i];
		//f[a[i]][b[i]]=min(f[a[i]][b[i]],c[i]);
	}
	f[0][0]=0;
	for(k=1;k<=n;k++)
	{
		for(i=sa[k];i>=a[k];i--)
		{
			for(j=sb[k];j>=b[k];j--)
			{
				f[i][j]=min(f[i][j],f[i-a[k]][j-b[k]]+c[k]);
			}
		}
	}
	for(i=1;i<maxn;i++)
	{
		for(j=1;j<maxn;j++)
		{
			if(i*nb==j*na)
				ans=min(ans,f[i][j]);
		}
	}
	if(ans==INF)
	{
		cout<<"-1";
		return 0;
	}
	cout<<ans;
	return 0;
}
