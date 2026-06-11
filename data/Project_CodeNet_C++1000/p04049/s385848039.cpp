#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,k;
  cin >> n >> k;
  vector<vector<int>> e(n);
  vector<pair<int,int>> ep(n-1);
  int a,b;
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
    ep[i]={a,b};
  }
  int ans=n;
  if(k%2){
    for(int i=0;i<n-1;i++){
      queue<int> bfs;
      vector<int> dist(n,IINF);
      dist[ep[i].first]=dist[ep[i].second]=0;
      bfs.push(ep[i].first);
      bfs.push(ep[i].second);
      int count=2;
      while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        if(dist[now]<k/2){
          for(auto nx:e[now]){
            if(dist[nx]==IINF){
              count++;
              dist[nx]=dist[now]+1;
              bfs.push(nx);
            }
          }
        }
      }
      ans=min(ans,n-count);
    }
  }else{
    for(int i=0;i<n;i++){
      queue<int> bfs;
      vector<int> dist(n,IINF);
      dist[i]=0;
      bfs.push(i);
      int count=1;
      while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        if(dist[now]<k/2){
          for(auto nx:e[now]){
            if(dist[nx]==IINF){
              count++;
              dist[nx]=dist[now]+1;
              bfs.push(nx);
            }
          }
        }
      }
      ans=min(ans,n-count);
    }
  }
  cout << ans << endl;
  return 0;
}