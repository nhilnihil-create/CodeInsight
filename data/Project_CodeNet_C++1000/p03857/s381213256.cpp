#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n,k,l;
  cin>>n>>k>>l;
  vector<int> hen[n],den[n];
  int a,b;
  for(int i=0;i<k;i++){
    cin>>a>>b;
    hen[a-1].push_back(b-1);
    hen[b-1].push_back(a-1);
  }
  for(int i=0;i<l;i++){
    cin>>a>>b;
    den[a-1].push_back(b-1);
    den[b-1].push_back(a-1);
  }
  int ban[n];k=0;
  queue<int> que;
  bool used[n]={};
  for(int i=0;i<n;i++){
    if(used[i])continue;
    used[i]=true;
    que.push(i);
    while(!que.empty()){
      a=que.front();
      que.pop();
      ban[a]=k;
      for(int j=0;j<hen[a].size();j++){
        if(!used[hen[a][j]]){
          que.push(hen[a][j]);
          used[hen[a][j]]=true;
        }
      }
    }
    k++;
  }
  map<pair<int,int>,int> mp;
  pair<int,int> p[n];
  k=0;for(int i=0;i<n;i++)used[i]=false;
  for(int i=0;i<n;i++){
    if(used[i])continue;
    used[i]=true;
    que.push(i);
    while(!que.empty()){
      a=que.front();
      que.pop();
      p[a]=make_pair(ban[a],k);
      mp[make_pair(ban[a],k)]++;
      for(int j=0;j<den[a].size();j++){
        if(!used[den[a][j]]){
          que.push(den[a][j]);
          used[den[a][j]]=true;
        }
      }
    }
    k++;
  }
  for(int i=0;i<n;i++)cout<<mp[p[i]]<<' ';
  return 0;
}
