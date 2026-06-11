#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=1e5+5;
int n,n1,n2;
vector<int> bfs(vector<vector<int> > &v,int x)
{
	vector<int> d(n+5,maxn);
	d[x]=0;
	queue<int>q;
	q.push(x);
	while(q.size())
	{
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++)
		{
			int a=v[t][i];
			if(d[a]>d[t]+1)
			{
				d[a]=d[t]+1;
				q.push(a);
			}
		}
	}
	return d;
}
int main()
{
	cin>>n;
	vector<vector<int> >v(n+5);
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
	    v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> v1=bfs(v,1),v2=bfs(v,n);
	for(int i=1;i<=n;i++)
	if(v1[i]<=v2[i])n1++;
	else n2++;
	if(n1>n2)
	puts("Fennec");
	else puts("Snuke");
	return 0;
}