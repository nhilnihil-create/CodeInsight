#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll k;
  cin>>k;
  if(k<=(ll)2*(1e16)){
    cout<<2<<endl;
    if(k%2){
      cout<<k/2+2<<" "<<k/2<<endl;
    }else{
      cout<<k/2+1<<" "<<k/2<<endl;
    }
  }else{
    ll num=k/((ll)(1e16));
    if(k%((ll)(1e16))){
      num++;
    }
    vvi list(100);
    ll now=0;
    for(int i=0;i<num;i++){
      for(int j=0;j<num;j++){
	list[i].pb(now);
	now=(now+1)%(num+1);
      }
    }
    cout<<num<<endl;
    for(int i=0;i<num;i++){
      cout<<list[k%num][i]+(k/num)<<" ";
    }
    cout<<endl;
  }
  return 0;
}
