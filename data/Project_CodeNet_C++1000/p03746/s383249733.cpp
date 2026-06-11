#include <bits/stdc++.h>
using namespace std;
#define int long long
bool used[100001]={};
vector<int> hen[100001];
vector<pair<int,int>> ans1,ans2;
void dfs(int a,vector<pair<int,int>>& ans){
  used[a]=true;
 
  for(int i=0;i<hen[a].size();i++){
    if(!used[hen[a][i]]){
      ans.push_back(make_pair(a,hen[a][i]));
      cerr<<a<<' '<<hen[a][i]<<endl;
      dfs(hen[a][i],ans);
      break;
    }
  }
  return ;
}
signed main() {
int n,m;
cin>>n>>m;
int a,b;
for(int i=0;i<m;i++){
  cin>>a>>b;a--;b--;
  hen[a].push_back(b);
  hen[b].push_back(a);
}
dfs(0,ans1);dfs(0,ans2);
cout<<ans1.size()+ans2.size()+1<<endl;
for(int i=ans1.size()-1;i>=0;i--){
  cout<<1+ans1[i].second<<' ';
}
cout<<1+ans1[0].first<<' ';
for(int i=0;i<ans2.size();i++){
  cout<<1+ans2[i].second<<' ';
}


return 0;
}
