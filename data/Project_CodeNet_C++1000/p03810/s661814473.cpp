#include<iostream>
#include<cstdio>
using namespace std;

int n,a[100009];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

bool Dfs(int x)
{
	int odd=0,even=0,flag=1;
	for (int i=1; i<=n; ++i)
		if (a[i]%2) {a[i]--; break;}
	int g=a[1];
	for (int i=2; i<=n; ++i) g=gcd(g,a[i]);
	for (int i=1; i<=n; ++i)
	{
		a[i]/=g;
		if (!(a[i]%2)) even++;
		else odd++;
		if (a[i]==1) flag=0;
	}
	if (even%2) return !x;
	if (odd!=1 || !flag) return x;
	return Dfs(x^1);
}

int main()
{
	int odd=0,even=0,flag=1;
	scanf("%d",&n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		if (a[i]%2) odd++;
		else even++;
		if (a[i]==1) flag=false;
	}
	if (even%2) puts("First");
	else if (odd!=1 || !flag) puts("Second");
	else if (Dfs(1)) puts("First");
	else puts("Second"); 
}