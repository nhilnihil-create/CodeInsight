#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int G=0,P=0,ans=0;
  for(int i=0;i<S.size();++i){
    if(S[i]=='g'){
      if(G>=P+1){
        ++ans;
        ++P;
      }
      else if(G==P)++G;
    }
    if(S[i]=='p'){
     if(G>=P+1) ++P;
     else if(G==P){
        --ans;
        ++G;
      }
    }
  }

  cout<<ans<<endl;
}
