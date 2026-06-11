#include<bits/stdc++.h>
using namespace std;
const int MAXN=20000+10;
int n,p[MAXN],a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)a[i]=a[i-1]+30000;
	for(int i=n;i>=1;--i)b[i]=b[i+1]+30000;
	for(int i=1;i<=n;++i)b[p[i]]-=n-i;
	for(int i=1;i<=n;++i)printf("%d ",a[i]);puts("");
	for(int i=1;i<=n;++i)printf("%d ",b[i]);puts("");
	return 0;
}