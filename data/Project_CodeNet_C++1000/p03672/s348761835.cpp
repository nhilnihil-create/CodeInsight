#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  int ans=S.size()-2;
  
  
  while(true){
    bool check=true;
    
    S.pop_back();
    S.pop_back();
    
    for(int i=0;i<S.size()/2;i++){
      if(S[i]!=S[i+S.size()/2]){
        check=false;
      }
    }
    
    if(check){
      cout<<ans<<endl;
      return 0;
    }
    
    ans=ans-2;
  }
}