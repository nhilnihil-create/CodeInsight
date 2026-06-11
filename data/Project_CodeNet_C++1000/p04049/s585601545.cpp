#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

template <class T>
void cout_vec2(const vector<vector<T>> &vec){
  rep(i,vec.size()){
    rep(j,vec[i].size()){
      cout<<vec[i][j]<<' ';
    }
    cout<<endl;
  }
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int n,k;
vector<vector<int>> g(2010);
vector<int> dist(2010,-1);
vector<bool> used(2010,false);

void dfs(int v,int d){
  if(used[v]) return ;
  dist[v]=d;
  used[v]=true;
  for(auto itr:g[v]) dfs(itr,d+1);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>k;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin>>a[i]>>b[i];
    a[i]--,b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  int ans=1e9;
  if(k%2==0){
    rep(i,n){
      int cnt=0;
      rep(j,n) used[j]=false;
      dfs(i,0);
      rep(j,n){
        if(dist[j]>k/2) cnt++;
      }
      ans=min(ans,cnt);
    }
  }else{
    rep(i,n-1){
      int u=a[i],v=b[i];
      queue<int> que;
      que.push(u);
      que.push(v);
      rep(i,n) dist[i]=-1;
      dist[u]=0,dist[v]=0;
      while(!que.empty()){
        int now=que.front();
        que.pop();
        for(auto itr:g[now]){
          if(dist[itr]==-1){
            dist[itr]=dist[now]+1;
            que.push(itr);
          }
        }
      }
      int cnt=0;
      rep(i,n){
        if(dist[i]>(k-1)/2) cnt++;
      }
      ans=min(ans,cnt);
    }
  }
  cout<<ans<<endl;
}