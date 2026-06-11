#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int INF=3;
int main(){
  int n,m;
  int min_cost[200005];
  vector<int>node[200005];
  cin>>n>>m;
  for(int i=0;i<=n;i++){
    min_cost[i]=INF;
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  
  queue<int>que;
  que.push(1);
  min_cost[1]=0;
  while(!que.empty()){
    int pos=que.front();que.pop();
    for(int i=0;i<node[pos].size();i++){
      int next=node[pos][i];
      if(min_cost[pos]+1<min_cost[next]){
	min_cost[next]=min_cost[pos]+1;
	que.push(next);
      }
    }
  }
  
  if(min_cost[n]==2){
    cout<<"POSSIBLE"<<endl;
  }else{
    cout<<"IMPOSSIBLE"<<endl;
  }
  return(0);
}