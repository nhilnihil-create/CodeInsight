#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string f=s.substr(0,s.size()/2);
  string b;
  while(1){
    s.pop_back();
    s.pop_back();
    f.pop_back();
    b=s.substr(f.size(),f.size());
    if(f==b)
      break;
  }
  cout<<s.size()<<endl;
}