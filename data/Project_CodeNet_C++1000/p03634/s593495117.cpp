#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

vector<vector<int>>g;
vector<vector<int64_t>>dist;
vector<int64_t>ans;
void dfs(int now,int back){
  for(int i=0;i<g[now].size();i++){
    int next=g[now][i];int nc=dist[now][i];
    if(next==back){continue;}
    ans[next]=ans[now]+nc;
    dfs(next,now);
  }
}

int main() {
  int N;
  cin>>N;
  g.resize(N);
  ans.resize(N);
  dist.resize(N);
  for(int i=0;i<N-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    g[a].emplace_back(b);dist[a].emplace_back(c);
    g[b].emplace_back(a);dist[b].emplace_back(c);
  }
  
  int Q,K;
  cin>>Q>>K;
  K--;
  dfs(K,-1);
  //for(int i=0;i<N;i++){cout<<ans[i]<<endl;}
  for(int i=0;i<Q;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    int64_t t=ans[x]+ans[y];
    cout<<t<<endl;
  }
  return 0;  
}