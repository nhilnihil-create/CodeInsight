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
  ll i,o,t,j,l,s,z;
  cin>>i>>o>>t>>j>>l>>s>>z;
  if(i>0&&j>0&&l>0){
    cout<<o+max((i-1)/2*2+(j-1)/2*2+(l-1)/2*2+3,i/2*2+j/2*2+l/2*2)<<endl;
  }else{
    cout<<o+i/2*2+j/2*2+l/2*2<<endl;
  }
  return 0;
}
