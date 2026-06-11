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
  vi A(n);
  vi B(n);
  vi co(n);
  ll ama=-1;
  ll bma=-1;
  for(int i=0;i<n;i++){
    cin>>A[i];
    ama=max(A[i],ama);
    if(i==0){
      co[0]=A[i];
    }else if(A[i]!=A[i-1])
      co[i]=A[i];
  }
  bool fl=true;
  for(int i=0;i<n;i++){
    cin>>B[i];
    bma=max(B[i],bma);
    if(co[i]>B[i])fl=false;
    if(i==n-1){
      if(co[i]>0&&B[i]!=co[i]){
	fl=false;
      }else{
	co[i]=B[i];
      }
    }
  }
  for(int i=n-2;i>=0;i--){
    if(B[i]!=B[i+1]){
      if(co[i]>0&&B[i]!=co[i])
	fl=false;
      else{
	co[i]=B[i];
      }
    }
  }
  ll ans=1;
  for(int i=0;i<n;i++){
    if(!co[i]){
      ll num=min(A[i],B[i]);
      ans*=num;
      ans%=MOD;
    }
  }
  if(fl&&bma==ama){
    cout<<ans<<endl;
  }else{
    cout<<0<<endl;
  }
  return 0;
}
