#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
typedef long long ll;
using namespace std;

void fail(){
    cout<<"No"<<endl;
    exit(0);
}

int main(){
  int N;
  cin>>N;
  vector<int> x(N);
  for(int i=0;i<N;i++) cin>>x[i];

  int M=N*N;
  vector<int> y(N+2,0);
  for(int i=1;i<=N;i++) y[i]=x[i-1];
  y[N+1]=M+1;
  sort(y.begin(),y.end());

  vector<int> ans(M+1,0);
  for(int i=0;i<N;i++) ans[x[i]]=i+1;
  int cnt=1;
  for(int i=1;i<=N;i++){
      int lef=ans[y[i]]-1;
      while(cnt<y[i]&&lef>0){
          if(ans[cnt]==0){
              ans[cnt]=ans[y[i]];
              lef--;
          }
          cnt++;
      }
      if(lef>0) fail();
  }

  cnt=M;
  for(int i=N;i>=1;i--){
      int rig=N-ans[y[i]];
      while(cnt>y[i]&&rig>0){
          if(ans[cnt]==0){
              ans[cnt]=ans[y[i]];
              rig--;
          }
          cnt--;
      }
      if(rig>0) fail();
  }

  cout<<"Yes"<<endl;
  for(int i=1;i<=M;i++) cout<<ans[i]<<" ";
  cout<<endl;

  return 0;
}
