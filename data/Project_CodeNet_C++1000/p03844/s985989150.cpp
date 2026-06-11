#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  string s;
  cin>>a>>s>>b;
  if(s=="+"){
     cout<<a+b;
  }
  else{
    cout<<a-b;
  }
  return 0;
}