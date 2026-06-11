#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,i;
  int64_t ans0=0,ans1=0,t=0;
  cin>>m;
  vector<int64_t> x(m);
  for(i=0;i<m;i++) cin>>x.at(i);
  for(i=0;i<m;i++){
    t+=x.at(i);
    if(i%2==0&&t<=0){
      ans0+=abs(t)+1;
      t=1;
    }
    else if(i%2==1&&t>=0){
      ans0+=abs(t)+1;
      t=-1;
    }
  }
  t=0;
  for(i=0;i<m;i++){
    t+=x.at(i);
    if(i%2==0&&t>=0){
      ans1+=abs(t)+1;
      t=-1;
    }
    else if(i%2==1&&t<=0){
      ans1+=abs(t)+1;
      t=1;
    }
  }
  cout<<min(ans0,ans1)<<endl;
}