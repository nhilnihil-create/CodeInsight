#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=110000;
int n,m;
int len=0;
vector<int> v[maxn];
struct node
{
  int x;
  int dist;
  int id;
}a[maxn];
int col[maxn][15];
int t;
inline void init()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
    v[i].push_back(i);
  scanf("%d",&t);
  for(int i=1;i<=t;i++)
    scanf("%d%d%d",&a[i].x,&a[i].dist,&a[i].id);
}
inline void dfs(int x,int dist,int id)
{
  if(dist==-1)
    return;
  if(col[x][dist])
    return;
  col[x][dist]=id;
  for(int i=0;i<v[x].size();i++)
  {
    int y=v[x][i];
    dfs(y,dist-1,id);
  }
}
inline void work_()
{
  for(int i=t;i>=1;i--)
    dfs(a[i].x,a[i].dist,a[i].id);
  for(int i=1;i<=n;i++)
    printf("%d\n",col[i][0]);
}
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	init();
	work_();
	//cout<<log(w)<<endl;
	return 0;
}
