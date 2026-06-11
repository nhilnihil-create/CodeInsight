#include<cstdio>
#include<string>
#include<string>
#include<iostream>
using namespace std;
const int mo=1e9+7;
long long n,f[5005][5005],ans,x;
string c;
int main()
{
	scanf("%lld",&n);
	cin>>c;x=c.size();
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=n;++j)
			f[i][j]=(2*f[i-1][j+1]+f[i-1][j-1<0?0:j-1])%mo;
	printf("%lld\n",f[n][x]%mo);
	return 0;
}