#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<(n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
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
  string s;cin>>s;
  if(s.size()%2)cout<<"No"<<endl;
  else{
    map<char,char>MP;
    MP['p']='q';
    MP['q']='p';
    MP['d']='b';
    MP['b']='d';
    bool fl=true;
    ll n=s.size();
    for(int i=0;i<n/2;i++){
      if(MP[s[n-i-1]]!=s[i])fl=false;
    }
    if(fl)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
