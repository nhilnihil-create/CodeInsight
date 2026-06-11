#include<bits/stdc++.h>
using namespace std;
const int g=200005;
int n,a[g],b[g],m;
long long s;

int main()
{
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(;a[i]<a[b[m]];m--)
			s+=(long long)a[b[m]]*(b[m]-b[m-1])*(i-b[m]);
		b[++m]=i;
	}
	for(;m;m--)
		s+=(long long)a[b[m]]*(b[m]-b[m-1])*(n-b[m]+1);
	printf("%lld",s);
	return 0;
}
