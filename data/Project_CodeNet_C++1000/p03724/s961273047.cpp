#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;

class Edge
{
	public:
	int cost;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

vector<Edge> g[100000];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,1));
		g[b].push_back(Edge(a,1));
	}
	bool ans=true;
	for(int i=0;i<n;i++)
	{
		if(g[i].size()&1)
			ans=false;
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}