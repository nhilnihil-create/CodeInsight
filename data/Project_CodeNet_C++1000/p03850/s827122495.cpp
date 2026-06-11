#include<bits/stdc++.h>
#define N (100009)
#define LL long long
using namespace std;

LL n,a[N],f[N][3];
char opt[N][2];

int main()
{
	cin>>n;
	for (int i=1; i<n; ++i)
		cin>>a[i]>>opt[i];
	cin>>a[n];
	f[1][0]=a[1]; f[1][1]=f[1][2]=-1e18;
	for (int i=2; i<=n; ++i)
		if (opt[i-1][0]=='+')
		{
			f[i][0]=max(f[i-1][0],f[i-1][1])+a[i];
			f[i][1]=f[i-1][1]-a[i];
			f[i][2]=f[i-1][2]+a[i];
		}
		else
		{
			f[i][0]=-1e18;
			f[i][1]=max(f[i-1][0],f[i-1][1])-a[i];
			f[i][2]=max(f[i-1][1],f[i-1][2])+a[i];
		}
	cout<<max(f[n][0],max(f[n][1],f[n][2]))<<endl;
}
