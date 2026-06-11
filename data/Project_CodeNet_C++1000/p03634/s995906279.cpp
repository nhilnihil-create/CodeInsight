#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
  int n;
  cin>>n;
  vector<P> path[n];
  rep(i,n-1){
    int a,b,c;
    cin>>a>>b>>c;
    path[a-1].push_back(P(b-1,c));
    path[b-1].push_back(P(a-1,c));
  }
  int q,k;
  cin>>q>>k;
  k--;
  ll dis[n];
  rep(i,n) dis[i]=-1;
  dis[k]=0;
  queue<int> que;
  que.push(k);
  while(que.size()){
    int r=que.front();
    que.pop();
    rep(i,path[r].size()){
      if(dis[path[r][i].first]==-1){
        dis[path[r][i].first]=dis[r]+path[r][i].second;
        que.push(path[r][i].first);
      }
    }
  }
  rep(i,q){
    int x,y;
    cin>>x>>y;
    cout<<dis[x-1]+dis[y-1]<<endl;
  }
}