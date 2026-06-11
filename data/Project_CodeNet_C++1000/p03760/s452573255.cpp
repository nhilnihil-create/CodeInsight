#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string O,E;
  cin>>O>>E;
  
  if(O.size()==E.size()){
    for(int i=0;i<O.size();i++){
      cout<<O[i]<<E[i];
    }
  }
  else{
    for(int i=0;i<E.size();i++){
      cout<<O[i]<<E[i];
    }
    cout<<O[O.size()-1];
  }
}