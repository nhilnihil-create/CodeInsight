#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=310;
int n,x,tot,b[N][N],f[N][N];
main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) scanf("%d",&f[i][j]);
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			if (f[i][j]>f[i][k]+f[k][j]) return puts("-1"),0;
			else if (i!=k&&k!=j&&f[i][j]==f[i][k]+f[k][j]) b[i][j]=1;
	long long ans=0;
	for (int i=1;i<=n;++i) for (int j=i+1;j<=n;++j) ans+=f[i][j]*(1-b[i][j]);
	printf("%lld",ans);
	return 0;
}