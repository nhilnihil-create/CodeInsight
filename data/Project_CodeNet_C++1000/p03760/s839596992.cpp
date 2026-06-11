#include <bits/stdc++.h>
using namespace std;

int main() {
  string o,e;
  cin>>o>>e;
  if(o.size()==e.size()){
    for(int i=0;i<o.size();i++){
      if(i==o.size()-1){
        cout<<o.at(i)<<e.at(i)<< endl;
        return 0;
      }
      cout<<o.at(i)<<e.at(i);
    }
  }
  else{
    for(int i=0;i<e.size();i++){
      cout<<o.at(i)<<e.at(i);
    }
  }
  cout<<o.at(o.size()-1)<< endl;
  return 0;
}