#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> ans(h);
  rep(i,h){
    cin>>ans[i];
  }
  rep(i,h){
    rep(j,2){
      cout<<ans[i]<<endl;
    }
  }
}