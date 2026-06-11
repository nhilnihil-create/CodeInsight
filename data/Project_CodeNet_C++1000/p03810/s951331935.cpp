#include<bits/stdc++.h>
using namespace std;
int a[101010];
int one,two,n,id;
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
bool dfs()
{
	//cerr<<dfs<<endl;
	--a[id];
	two=0; one=0;
	int x=a[1];
	for (int i=2;i<=n;++i) x=gcd(x,a[i]);
	for (int i=1;i<=n;++i)
	{
		a[i]/=x;
		if (a[i]%2==0) ++two;
		else ++one,id=i;
	}
	if (two%2==1) return 0;
	else if (one>=2 || a[id]==1) return 1;
	return (!dfs());
}
int main()
{
	//freopen("gold.in","r",stdin);
	//freopen("gold.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
	{
		if (a[i]%2==0) ++two;
		else ++one,id=i;
	}
	if (two%2==1) printf("First\n");
	else if (one>=2 || a[id]==1) printf("Second\n");
	else if (dfs()) printf("First\n");
	else printf("Second\n");
	return 0;
}