#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
vector<int> G[N];
int f[N],n,k,ans=0;
int dep[N];
void dfs(int u)
{
	dep[u]=0;
	for(int v:G[u])
	{
		dfs(v);
		dep[u]=max(dep[u],dep[v]);
	}
	dep[u]++;
	if(dep[u]==k&&u!=1&&f[u]!=1) dep[u]=0,ans++;
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) f[i]=read();
	if(f[1]!=1) ans++,f[1]=1;
	for(int i=2;i<=n;i++) G[f[i]].pb(i);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}


