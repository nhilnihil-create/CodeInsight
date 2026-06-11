#include<bits/stdc++.h>
using namespace std;
queue<int>q;
const int N=100005;
int visit[2][N];
vector<int>v[N];
int n;
inline void BFS(int o,int k)
{
	q.push(k);
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		int t=q.front();q.pop();
		visit[o][x]=t;
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(!visit[o][y])
			{
				q.push(y);
				q.push(t+1);
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	BFS(0,1);
	BFS(1,n);
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(visit[0][i]<=visit[1][i])x++;
		else y++;
	}
	if(x>y)cout<<"Fennec\n";
	else cout<<"Snuke\n";
}