#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ECHO(x) cout<<x<<endl;
#define MEMSET(a, n, x) REP(i, n) a[i]=x;
#define ARRIN(a, n) REP(i, n) cin>>a[i];
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;

vector<vector<int>>edge;
vector<int> color;
int fec=1, snc=1;
queue<P> q;

int main(){
  int n;
  cin>>n;
  edge=vector<vector<int>> (n);
  color=vector<int>(n, -1);
  int a, b;

  REP(i, n-1){
    cin>>a>>b;
    --a;
    --b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  q.push(make_pair(0, 0));
  q.push(make_pair(n-1, 1));
  color[0]=0;
  color[n-1]=1;
  while(!q.empty()){
      int e=q.front().first;
      int c=q.front().second;
      q.pop();
      for(int i=0; i<edge[e].size(); ++i){
        int to=edge[e][i];
        if(color[to]!=-1) continue;
        q.push(make_pair(to, c));
        color[to]=c;
        if(c==0)++fec;
        else ++snc;
      }
  }
  if(fec>snc) cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;

  return 0;
}
