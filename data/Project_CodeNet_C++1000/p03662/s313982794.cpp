#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#define MAX 100005
#define INF 100000005
#define pb push_back
using namespace std;

int n;
vector<vector<int> > g(MAX);

vector<int> func(int s)
{
	int f,t;
	int i;
	vector<int> d(MAX);
	 
	queue<int> q;
	
	for (i=1;i<=n;i++)
	{
		d[i]=INF;
	}
	q.push(s);
	d[s]=0;
	while (!q.empty())
	{
		f=q.front();
		q.pop();
		for (i=0;i<g[f].size();i++)
		{
			t=g[f][i];
			if (d[t]>d[f]+1)
			{
				d[t]=d[f]+1;
				q.push(t);
			}
		}
	}
	
	return d;
}
int main()
{
	
	int i,j;
	int x,y;
	int n1,n2;
	vector<int>d1,d2;
	
	cin>>n;
	for (i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	d1=func(1);
	
	d2=func(n);
	
	
	n1=0;
	n2=0;
	for (i=2;i<=n-1;i++)
	{
		if (d1[i]<=d2[i])
		{
			n1++;
		}
		else
		{
			n2++;
		}
	}
	if (n1>n2)
	{
		cout<<"Fennec";
	}
	else
	{
		cout<<"Snuke";
	}
	return 0;
}