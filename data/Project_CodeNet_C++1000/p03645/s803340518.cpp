#include<bits/stdc++.h>
using namespace std;
             
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> Pi;
typedef map<ll,ll> mi;
             
template<class T> T nrem(T x,T y){return ((x%y)+y)%y;}
             
#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define Forl0(i,n) for(ll i=0;i<n;++i)
#define Forl1(i,n) for(ll i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cs 200005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
    {
         #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
        #endif
    }

vector<int> adj[cs];
int visited[cs];
int level[cs];

void bfs(int s)
{
    queue <int> Q;
    Q.push(s);

    visited[s]=1;
    level[s]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++)
            if(visited[adj[u][i]]==0)
        {
            int v=adj[u][i];
            visited[v]=1;
            level[v]=level[u]+1;
            Q.push(v);
        }
    }
}

int main()
{  
    IOS
    in();
    
   int n,m;
   cin>>n>>m;

   For0(i,m)
   {
       int a,b;
       cin>>a>>b;
       adj[a].pb(b);
       adj[b].pb(a);
   }
    
    memset(level,-1,sizeof level);

    bfs(1);
    if(level[n]<=2&&level[n]!=-1)
    cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}