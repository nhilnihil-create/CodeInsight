//Bismillahir Rahmanir Rahim 
#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define gcd(a,b) __gcd(a,b)
#define endl '\n'
const int N=2e5+10;
const int inf=1e9;
const int mod=1e9+7;

vector<int>adj[N];
bool vis[N];
int dis[N];

int  main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
    	int u, v;
    	cin >> u >> v;

    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    	dis[i]=inf;

    queue<int>q;
    q.push(1);
    vis[1]=1;
    dis[1]=0;

    while(!q.empty())
    {
    	int u=q.front();
    	//cout << u << endl;
    	q.pop();

    	for(auto v: adj[u])
    	{
    		if(vis[v]==0)
    		{
    			dis[v]=dis[u]+1;
    			//cout << v <<  " " << dis[v] << endl;
    			vis[v]=1;
    			q.push(v);
    		}
    	}
    }

    //cout << dis[n] << endl;

    if(dis[n]<=2)
    	cout << "POSSIBLE" << endl;
    else
    	cout << "IMPOSSIBLE" << endl;
	
	return 0;
}