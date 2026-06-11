#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;
//author_name:
//date://
//title:
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define ep emplace_back
#define mp make_pair
//ÒòÎªÇÓÅ³£¬ËùÒÔÌÓ±ÜÉúÃü£¬ÒÔ²»µÖ¿¹ÔÚ×îºÚ°µµÄ³ÁÂÙÖÐÉú³ö½¾°Á£¬ÒòÎª½¾°Á£¬ËùÒÔ²»Ñ¡ÔñÉú£¬ËùÒÔ¾Ü³â´Ö±ÉµÄÀÖ¹ÛÖ÷Òå¡£
//Ìì²ÅµÄ±¯¾çµØÓÚ±»Ð¡¶øÊæÊÊµÄÃûÍûËùÊø¸¿¡£
//It's human to lie. Most of the time we can't even be honest with ourselves.
typedef long long ll;
typedef pair<int,int> pii;

vector<pair<int,pii>> query;

int n,m,q;
vector<int> g[100010];
int max_d[100010];
int col[100010];

inline void dfs(int u,int d,int c)
{
	if(max_d[u]>=d) return;
	max_d[u]=d;
	if(col[u]==-1) col[u]=c;
	for(int i=0;i<g[u].size();i++)
		dfs(g[u][i],d-1,c);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		query.push_back(mp(a,mp(b,c)));
	}
	reverse(query.begin(),query.end());
	memset(max_d,-1,sizeof max_d);
	memset(col,-1,sizeof col);
	for(int i=0;i<q;i++)
		dfs(query[i].first,query[i].second.first,query[i].second.second);
	for(int i=1;i<=n;i++)
		printf("%d\n",col[i]==-1?0:col[i]);
	return 0;
}