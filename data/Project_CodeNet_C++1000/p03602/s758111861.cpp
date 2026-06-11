#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 310
using namespace std;
long long a[maxn][maxn],n,b[maxn][maxn],ans;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		scanf("%lld",&a[i][j]),b[i][j]=a[i][j],ans+=a[i][j];
		ans/=2;
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(a[i][j]!=b[i][j]) {
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n-1;++i)
	for(int j=i+1;j<=n;++j)
	{
		for(int k=1;k<=n;++k)
		if(a[i][j]==a[i][k]+a[k][j]&&k!=i&&k!=j) 
		{
		ans-=a[i][j];
		break;
		}
	}
	cout<<ans<<endl;
	return 0;
}