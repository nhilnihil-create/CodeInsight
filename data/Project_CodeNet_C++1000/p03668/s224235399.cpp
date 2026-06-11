#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define en '\n'
vector<int> adj[100005];
bool vis[100005];
int c[100005];
int dfs(int s)
{
    vis[s]=1;
    int ch=0;
    f(i,0,adj[s].size())
    {
        int o=0;
        if(vis[adj[s][i]]==0)
        {
            o=dfs(adj[s][i])+1;
        }
        ch=ch^o;
    }
    return ch;
}
int main()
{
	IOS;
	int t=1;
//	cin>>t;
	while(t--)
	{
        int n,x,y;
        cin>>n;
        f(i,0,n-1)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        x=dfs(1);
        if(x)
            cout<<"Alice";
        else
            cout<<"Bob";
	}
}
