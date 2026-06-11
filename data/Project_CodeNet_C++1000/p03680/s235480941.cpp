#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define evn(x) (!((x)&1))
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

int n;
bool vis[MAX];
vector<int> gp[MAX];
int dist[MAX];

void connect(int a, int b)	{
	gp[a].push_back(b);
}

void bfs(int a)	{
	//if(vis[a])	return;
	vis[a]=1;
	queue<int> q;
	q.push(a);
	while(!q.empty())	{
		q.pop();
		for(auto p:gp[a])	{
			if(vis[p])	continue;
			q.push(p);
			vis[p]=1;
			dist[p]=1+dist[a];
			//if(a==1 && p==2)	{cout << 1 << endl; exit(0);}
		}
		a=q.front();
	}
}

void solve()	{
	cin >> n;
	memset(dist,0,sizeof(dist));
	int x;
	for(int i=0; i<n; i++)	{
		cin >> x;
		connect(i+1,x);
	}
	bfs(1);

	if(vis[2])	cout << dist[2] << endl;
	else cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}

