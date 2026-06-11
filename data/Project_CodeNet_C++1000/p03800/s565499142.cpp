#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#define LL long long
#define MP make_pair
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
bool c[100010];
bool a[100010];
int n;
void out()
{
	for (int i=0;i<n;i++) printf(a[i] ? "W" : "S");
	exit(0);
}
void dfs(int x)
{
	/*cout <<x<<" ##############\n";
	for (int i=0;i<n;i++) cout <<a[i];
	cout <<"\n";*/
	if (x==n)
	{
		if (a[x-1]==a[1] && a[0]^c[0]==1) return;
		if (a[x-1]!=a[1] && a[0]^c[0]==0) return;
		if (a[x-2]==a[0] && a[x-1]^c[x-1]==1) return;
		if (a[x-2]!=a[0] && a[x-1]^c[x-1]==0) return;
		out();
		return;
	}
	if (x<2)
	{
		a[x]=1;
		dfs(x+1);
		a[x]=0;
		dfs(x+1);
	}
	else
	{
		if (a[x-1]^c[x-1]==0) a[x]=a[x-2];
		else a[x]=a[x-2]^1;
		dfs(x+1);
	}
}
int main()
{
	cin >>n;
	for (int i=0;i<n;i++)
	{
		char ch;
		cin >>ch;
		c[i]=(ch=='o' ? 0 : 1);
	}
	//fill(a,a+n,-1);
	dfs(0);
	cout <<"-1";
	return 0;
}