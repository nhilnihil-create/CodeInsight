#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  string o,e;
  cin>>o>>e;
  for(int i=0;i<min(o.size(),e.size());i++){
    cout<<o.at(i)<<e.at(i);
  }
  if(o.size()>e.size()){
    cout<<o[o.size()-1];
  }
}