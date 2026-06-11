#include<bits/stdc++.h>
using namespace std;
int func(string s,char X){
  for(int i=0;i<s.size();i++){
    if(X==s.at(i)){
      return 1;
    }
  }
  return 0;
}
int main(){
  string s;
  cin>>s;
  int N=func(s,'N'),W=func(s,'W'),S=func(s,'S'),E=func(s,'E');
  if(N!=S || W!=E)
    cout<<"No";
  else
    cout<<"Yes";
}