#include<bits/stdc++.h>
using namespace  std;

int main(){
  string s;
  cin>>s;
  for(int i=0;i<=3;i++){
    cout<<s[i];
  }
  cout<<" ";
  for(int i=4;i<=s.size()-1;i++){
    cout<<s[i];
  }
  cout<<endl;
}
