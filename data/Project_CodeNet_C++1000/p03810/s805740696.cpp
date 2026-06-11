#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<ctime>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int n,a[1000000],i,g;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
bool solve()
{
	int ji=0,ou=0,last;
	for (int i=1;i<=n;i++) if (a[i]&1)ji++,last=i;else ou++;
	if (ou&1) return true;
	if (ji>=2) return false;
	if (a[last]==1) return false;
	a[last]--;
	g=a[1];
	for (int i=2;i<=n;i++) 
	g=gcd(g,a[i]);
	for (int i=1;i<=n;i++) a[i]/=g;
	return !solve();
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if (solve()) printf("First\n");
	else printf("Second\n");
	return 0;
}