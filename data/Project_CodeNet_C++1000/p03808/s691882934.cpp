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
  ll n;cin>>n;
  vector<ll>A(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin>>A[i];
    sum+=A[i];
  }

  if(sum%((ll)n*(n+1)/2)==0){
    ll cnt=0;
    bool flag=true;
    ll num=sum/((ll)n*(n+1)/2);
    for(int i=0;i<n;i++){
      ll d=A[(i+1)%n]-A[i]-num;
      if(d>0)flag=false;
      if((-d)%n)flag=false;
      else{
	cnt+=(-d)/n;
      }
    }
    if(cnt!=num)flag=false;
    YES(flag);
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
