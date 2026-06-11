#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int array[305][305]={0};
int idx[305]={0};
bool judge(int border){
  for(int i=1;i<=n;i++) idx[i]=1;
  int cnt[305]={0};
  bool used[305];
  for(int i=1;i<=m;i++) used[i]=false;
  while(1){
    for(int i=0;i<=m;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[array[i][idx[i]]]++;
    bool f=false;
    for(int i=1;i<=m;i++){
      if(cnt[i]>border) used[i]=true;
    }
    for(int i=1;i<=n;i++){
      while(used[array[i][idx[i]]]){
        idx[i]++;
        f=true;
        if(idx[i]>m) return false;
      }
    }
    if(!f) return true;
  }
}
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>array[i][j];
    }
  }
  int lb=0,rb=n+1;
  while(rb-lb>1){
    int mid=(lb+rb)/2;
    if(judge(mid)) rb=mid;
    else lb=mid;
  }
  cout<<rb<<endl;
}
