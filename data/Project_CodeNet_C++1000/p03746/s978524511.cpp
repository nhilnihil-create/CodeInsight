#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
#define vi vector<ll>
#define vvi vector<vi>
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=1010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};
vvi E(100010);
vi ans(300000);
int n;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m;cin>>n>>m;
  int lnum=1,rnum=2;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    E[a].pb(b);
    E[b].pb(a);
    if(i==0){lnum=a;rnum=b;}
  }
  bool flag=false;
  int leaf;
  int left=149999;
  int right=150002;

  ans[150000]=lnum;
  ans[150001]=rnum;
  bool used[100100]={};
  used[lnum]=true;used[rnum]=true;
  while(1){
    bool lfl=true;
    bool rfl=true;
    int lto;
    for(int i=0;i<E[lnum].size();i++){
      if(!used[E[lnum][i]]){
	lto=E[lnum][i];
	used[E[lnum][i]]=true;
	lfl=false;
	lnum=lto;
	break;
      }
    }
    if(!lfl){
      ans[left--]=lto;
      continue;
    }
    int rto;
    for(int i=0;i<E[rnum].size();i++){
      if(!used[E[rnum][i]]){
	rto=E[rnum][i];
	used[E[rnum][i]]=true;
	rfl=false;
	rnum=rto;
	break;
      }
    }
    if(!rfl){
      ans[right++]=rto;
      continue;
    }
    cout<<right-left-1<<endl;
    for(int i=0;i<300000;i++)
      if(ans[i]>0)
	cout<<ans[i]<<" ";
    cout<<endl;
    break;
  }
  return 0;
}
