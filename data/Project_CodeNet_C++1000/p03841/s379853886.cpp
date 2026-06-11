#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n;
  cin>>n;
  priority_queue<P,vector<P>,greater<P>> unused;
  queue<int> after;
  bool used[505];
  for(int i=0;i<=n;i++) used[i]=false;
  int array[505]={0};
  vector<int> ans(n*n+1,0);
  for(int i=1;i<=n;i++){
    int ps;
    cin>>ps;
    for(int j=1;j<i;j++) {
      unused.push(P(ps,i));
    }
    array[ps]=i;
    ans[ps]=i;
  }
  for(int i=1;i<=n*n;i++){
    if(ans[i]!=0){
      used[ans[i]]=true;
      for(int j=ans[i]+1;j<=n;j++) after.push(ans[i]);
      continue;
    }
    if(!unused.empty()){
      P p=unused.top();
      unused.pop();
      int tp=p.second;
      if(used[tp]){
        cout<<"No"<<endl;
        return 0;
      }
      ans[i]=tp;
    }
    else{
      if(after.empty()){
        cout<<"No"<<endl;
        return 0;
      }
      ans[i]=after.front();
      after.pop();
    }
  }
  if(!unused.empty()||!after.empty()){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<=n*n;i++) cout<<ans[i]<<(i==n*n?"\n":" ");
}
