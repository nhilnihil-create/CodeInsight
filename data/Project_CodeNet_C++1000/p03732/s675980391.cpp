#include <iostream>
using namespace std;
int n,W,ans;
int f[150][150][450],w[150],c[150];
int main()
{
	int n,W;
	cin>>n>>W;
	for (int i=0;i<n;i++) cin>>w[i]>>c[i];
	for (int i=0;i<n;i++) for (int j=0;j<=i;j++) for (int k=0;k<=3*j;k++)
	  {
		f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]);
		f[i+1][j+1][k+w[i]-w[0]]=max(f[i+1][j+1][k+w[i]-w[0]],f[i][j][k]+c[i]);
	  }
	for(int i=0; i<=n; i++) for(int j=0; j<=3*i; j++)
	  {
		long long nowW=(long long)w[0]*i+j;
		if(nowW<=W) ans=max(ans,f[n][i][j]);
	  }
	cout<<ans;
}