#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
vector<int> g[100010];
int dfs(int x,int f)
{
	int s=0;
	for(auto v:g[x])
		if(v!=f)
			s^=dfs(v,x)+1;
	return s;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(dfs(1,0))
		printf("Alice\n");
	else
		printf("Bob\n");
	return 0;
}