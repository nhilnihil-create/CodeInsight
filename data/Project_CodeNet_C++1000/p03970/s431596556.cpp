#include<iostream>
using namespace std;
signed main(){
  string s,c="CODEFESTIVAL2016";
  int count=0;
  cin>>s;
  for(int i=0;i<16;i++){
    if(s[i]!=c[i]){
      count++;
    }
  }
  cout<<count<<'\n';
  return(0);
}
