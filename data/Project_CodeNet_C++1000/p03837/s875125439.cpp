#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=101;
int M_MAX=1000;
int INF=1e5;
struct edge{int from, to, cost;};
int main()
{
  int n,m,a,b,c,i,j,k,res=0;
  int d[N_MAX][N_MAX];
  edge e[M_MAX];
  cin >> n >> m;
  for(i=1;i<=n;i++)
    fill(d[i]+1,d[i]+n+1,INF);
  for(i=1;i<=n;i++)
    d[i][i]=0;
  for(i=0;i<m;i++){
    cin >> a >> b >> c;
    e[i].from=a;
    e[i].to=b;
    e[i].cost=c;
    d[a][b]=c;
    d[b][a]=c;
  }
  for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  for(i=0;i<m;i++){
    a=e[i].from;
    b=e[i].to;
    c=e[i].cost;
    if(d[a][b]<c)
      res++;
  }
  cout << res << endl;
  return 0;
}