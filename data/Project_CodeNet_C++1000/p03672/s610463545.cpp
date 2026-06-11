#include <bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  int ans=0;
  for(int i=2;i<S.size();i+=2){
    for(int j=0;j<i/2;j++){
      if(S.at(j)!=S.at(i/2+j))break;
      if(j==i/2-1)ans=i;
    }
  }
  cout<<ans<<endl;
}