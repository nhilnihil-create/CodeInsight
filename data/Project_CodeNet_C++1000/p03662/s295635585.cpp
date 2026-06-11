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
using namespace std;
struct Grid{int x,y,t;};
struct Edge{int to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=1010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(int from,int to,int cost){E[from-1].pb({to-1,cost});}
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  vector<vector<int>>ve(n);
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    ve[--a].pb(--b);
    ve[b].pb(a);
  }
  int used[n+100]={};
  used[0]=1;used[n-1]=2;
  queue<int>fe,su;
  fe.push(0);
  su.push(n-1);
  int cnt=0;
  while(!fe.empty()||!su.empty()){
    if(cnt%2==0){
      vector<int>point;
      while(!fe.empty()){
	int now=fe.front();
	fe.pop();
	for(int i=0;i<ve[now].size();i++){
	  if(used[ve[now][i]]==0){
	    used[ve[now][i]]=1;
	    point.pb(ve[now][i]);
	  }
	}
      }
      for(int i=0;i<point.size();i++)fe.push(point[i]);
      cnt++;
    }else{
      vector<int>point;
      while(!su.empty()){
	int now=su.front();
	su.pop();
	for(int i=0;i<ve[now].size();i++){
	  if(used[ve[now][i]]==0){
	    used[ve[now][i]]=2;
	    point.pb(ve[now][i]);
	  }
	}
      }
      for(int i=0;i<point.size();i++)su.push(point[i]);
      cnt++;
    }
  }
  int fenec=0,snuke=0;
  for(int i=0;i<n;i++)
    if(used[i]==1)fenec++;
    else snuke++;
  if(fenec>snuke)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
  return 0;
}
