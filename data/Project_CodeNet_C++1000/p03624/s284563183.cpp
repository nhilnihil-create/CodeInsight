#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  vector<int> check(26);
  
  
  for(int i=0;i<S.size();i++){
    char x='a';
    for(int j=0;j<26;j++){
      if(S[i]==x+j){
        check[j]=1;
      }
    }
  }
  
  for(int i=0;i<26;i++){
    if(check[i]==0){
      cout<<(char)(i+'a')<<endl;
      return 0;
    }
  }
  
  cout<<"None"<<endl;
}