#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

vector<int> g[101000];
int dist[101000],res[101000]={};
void dfs(int v,int d,int c){
   if(d<0)return;
   if(d<=dist[v])return;
   dist[v]=d; if(!res[v])res[v]=c; d--;
   for(int to:g[v])dfs(to,d,c);
}
int que[101000][3];

int main(){
   int n,m,q; scanf("%d%d",&n,&m);
   memset(dist,-1,sizeof(dist));
   rep(i,0,m){
      int u,v; scanf("%d%d",&u,&v); u--; v--;
      g[u].push_back(v); g[v].push_back(u);
   }
   scanf("%d",&q);
   rep(i,0,q)rep(j,0,3)scanf("%d",&que[i][j]);
   rrep(i,q-1,-1){que[i][0]--; dfs(que[i][0],que[i][1],que[i][2]);}
   rep(i,0,n)printf("%d\n",res[i]);
   return 0;
}