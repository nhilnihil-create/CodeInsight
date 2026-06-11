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
ll dp[210000];
ll to[210000][30];
ll nex[30];
bool can[210000];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;cin>>s;
  s='S'+s+'S';
  for(int i=0;i<30;i++)nex[i]=s.size()-1;
  for(int i=s.size()-1;i>=0;i--){
    for(int j=0;j<26;j++)to[i][j]=nex[j];
    if(s[i]!='S')nex[s[i]-'a']=i;
  }
  // for(int i=0;i<210000;i++)back[i]=mp(llINF,llINF);

  for(int i=0;i<210000;i++){
    dp[i]=llINF;
  }

  dp[0]=0;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
      dp[to[i][j]]=min(dp[to[i][j]],dp[i]+1);
    }
  }

  can[s.size()-1]=true;
  for(int i=s.size()-1;i>=0;i--)
    for(int j=0;j<26;j++)
      if(dp[to[i][j]]==dp[i]+1 && can[to[i][j]])can[i]=true;
 
  ll now=0;
  while(now != s.size()-1){
    
    for(int i=0;i<26;i++)
      if(dp[to[now][i]] == dp[now]+1 && can[to[now][i]]){
	cout<<(char)('a'+i);
	now=to[now][i];
	break;
      }
  }
  cout<<endl;
  return 0;
}
