#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t H,W;
  cin>>H>>W;

  int64_t ans=H*W;

  for(int64_t i=1;i<W;++i){
    int64_t j=H/2;
    vector<int64_t> cho(3);
    cho[0]=i*H,cho[1]=(W-i)*j,cho[2]=(W-i)*(H-j);
    sort(cho.begin(),cho.end());
    ans=min(ans,cho[2]-cho[0]);
  }
  for(int64_t i=1;i<H;++i){
    int64_t j=W/2;
    vector<int64_t> cho(3);
    cho[0]=i*W,cho[1]=(H-i)*j,cho[2]=(H-i)*(W-j);
    sort(cho.begin(),cho.end());
    ans=min(ans,cho[2]-cho[0]);
  }
  if(H>=3){
    if(H%3==0) ans=0;
    else ans=min(ans,W);
  }
  if(W>=3){
    if(W%3==0) ans=0;
    else ans=min(ans,H);
  }

  cout<<ans<<endl;

}