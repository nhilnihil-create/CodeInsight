#include <bits/stdc++.h>
#include <algorithm>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  int x,y;
  
  
  for(int i=0;i<S.size();i++){
    if(S[i]=='A'){
      x=i+1;
      break;
    }
  }
  
  for(int j=S.size()-1;j>=0;j--){
    if(S[j]=='Z'){
      y=j+1;
      break;
    }
  }
  
  
  cout<<y-x+1<<endl;
}