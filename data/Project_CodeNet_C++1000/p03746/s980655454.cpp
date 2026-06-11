#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;

  vector<int> v[n+1];
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int now=1;
  int used[n+1]={};
  vector<int> ans1,ans2;
  ans1.push_back(1);
  used[1]=1;

  for(;;){
    bool flag=0;
    for(int i=0;i<v[now].size();i++){
      int next=v[now][i];
      if(used[next]) continue;
      used[next]=1;
      ans1.push_back(next);
      now=next;
      flag=1;
      break;
    }
    if(!flag) break;
  }

  now=1;
  for(;;){
    bool flag=0;
    for(int i=0;i<v[now].size();i++){
      int next=v[now][i];
      if(used[next]) continue;
      used[next]=1;
      ans2.push_back(next);
      now=next;
      flag=1;
      break;
    }
    if(!flag) break;
  }

  cout<<ans1.size()+ans2.size()<<endl;
  for(int i=ans2.size()-1;i>=0;i--) cout<<ans2[i]<<" ";
  for(int i=0;i<ans1.size();i++) cout<<ans1[i]<<" ";
  cout<<endl;

  return 0;
}
