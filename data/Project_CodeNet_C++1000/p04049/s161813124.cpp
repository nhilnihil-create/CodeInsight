#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> P;
vector<int> node[2005];
int main(){
  int n,k;
  cin>>n>>k;
  if(k%2==0){
    for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    int ans=1e5;
    for(int i=1;i<=n;i++){
      int kans=0;
      queue<P> que;
      que.push(P(i,0));
      bool used[2005];
      for(int j=0;j<2005;j++) used[j]=false;
      used[i]=true;
      while(!que.empty()){
        P p=que.front();
        que.pop();
        int pos=p.first,dis=p.second;
        if(dis>k/2) kans++;
        for(int j=0;j<node[pos].size();j++){
          int to=node[pos][j];
          if(!used[to]){
            used[to]=true;
            que.push(P(to,dis+1));
          }
        }
      }
      ans=min(ans,kans);
    }
    cout<<ans<<endl;
  }
  else{
    vector<P> v;
    for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      node[a].push_back(b);
      node[b].push_back(a);
      v.push_back(P(a,b));
    }
    int ans=1e5;
    for(int i=0;i<n-1;i++){
      int kans=0;
      int dist[2005]={0};
      queue<P> que;
      que.push(P(v[i].first,0));
      que.push(P(v[i].second,0));
      bool used[2005];
      for(int j=0;j<2005;j++) used[j]=false;
      used[v[i].first]=true;
      used[v[i].second]=true;
      while(!que.empty()){
        P p=que.front();
        que.pop();
        int pos=p.first,dis=p.second;
        if(dis>(k-1)/2) kans++;
        for(int j=0;j<node[pos].size();j++){
          int to=node[pos][j];
          if(!used[to]){
            used[to]=true;
            que.push(P(to,dis+1));
          }
        }
      }
      ans=min(ans,kans);
    }
    cout<<ans<<endl;
  }
}
