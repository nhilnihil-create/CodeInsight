#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string o,e;
  cin>>o>>e;
  if(o.size()>e.size()){
    rep(i,e.size()){
      cout<<o[i];
      cout<<e[i];
    }
    cout<<o[o.size()-1]<<endl;
  }
  else{
    rep(i,o.size()){
      cout<<o[i];
      cout<<e[i];
    }
    cout<<endl;
  }
}