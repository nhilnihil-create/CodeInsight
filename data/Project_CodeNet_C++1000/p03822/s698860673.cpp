#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> node[100005];
int par[100005]={0};
int dfs(int pos){
  if(node[pos].size()==0) return 0;
  vector<int> v;
  for(int i=0;i<node[pos].size();i++) v.push_back(dfs(node[pos][i]));
  sort(v.begin(),v.end(),greater<int>());
  int ret=0;
  for(int i=0;i<v.size();i++) ret=max(ret,v[i]+i+1);
  return ret;
}
int main(){
  int n;
  cin>>n;
  for(int i=2;i<=n;i++) {
    cin>>par[i];
    node[par[i]].push_back(i);
  }
  cout<<dfs(1)<<endl;
}
