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
//end

vector<int> g[101000];

int dfs(int v,int p){
   int res=0;
   for(int nxt:g[v])if(nxt!=p)res^=dfs(nxt,v);
   return res+1;
}

int main(){
   int n; scanf("%d",&n);
   rep(_,0,n-1){
      int x,y; scanf("%d%d",&x,&y); x--; y--;
      g[x].push_back(y); g[y].push_back(x);
   }
   printf(dfs(0,-1)==1?"Bob\n":"Alice\n");
   return 0;
}