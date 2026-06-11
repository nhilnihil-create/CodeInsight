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
  int h,w,n;cin>>h>>w>>n;
  int cnt[100]={};
  vector<pair<int,int> >bl(n);
  map<pair<int,int>,int>MP2;
  for(int i=0;i<n;i++){
    cin>>bl[i].F>>bl[i].S;
    MP2[mp(bl[i].F,bl[i].S)]=1;
  }
  sort(ALL(bl));
  map<pair<int,int>,int >MP;
  for(int i=0;i<n;i++){
    int jl=max(1,bl[i].F-2),jr=min(bl[i].F,h-2);
    int kl=max(1,bl[i].S-2),kr=min(bl[i].S,w-2);
    for(int j=jl;j<=jr;j++){
      for(int k=kl;k<=kr;k++){
	if(MP[mp(j,k)]==0){
	  MP[mp(j,k)]=1;
	  int cntt=0;
	  for(int l=j;l<=j+2;l++)
	    for(int lll=k;lll<=k+2;lll++)
	      cntt+=MP2[mp(l,lll)];
	  cnt[cntt]++;
	}
      }
    }
  }
  int sum=0;
  for(int i=1;i<=9;i++)sum+=cnt[i];
  cout<<(ll)(h-2)*(w-2)-sum<<endl;
  for(int i=1;i<=9;i++)cout<<cnt[i]<<endl;
  return 0;
}
