#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
#include<stack>
#include<queue>
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
queue<int> q1;
stack<int> q2;
int main()
{
	ll n;
	scanf("%lld",&n);
	int m=0;
	n++;
	while(n>1)
	{
		if(n&1)
		{
			q1.push(++m);
			n--;
		}
		else
		{
			q2.push(++m);
			n>>=1;
		}
	}
	printf("%d\n",2*m);
	while(!q1.empty())
	{
		printf("%d ",m-q1.front()+1);
		q1.pop();
	}
	while(!q2.empty())
	{
		printf("%d ",m-q2.top()+1);
		q2.pop();
	}
	int i;
	for(i=1;i<=m;i++)
		printf("%d ",i);
	return 0;
}