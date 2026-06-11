#include<bits/stdc++.h>
using namespace std;

int main(){
  string T;
  cin >> T;
  int N=0, S=0, E=0, W=0;
  for(int i=0; i<T.size(); i++){
    if(T.at(i)=='N'){
      N=1;
    }
    if(T.at(i)=='S'){
      S=1;
    }
    if(T.at(i)=='E'){
      E=1;
    }
    if(T.at(i)=='W'){
      W=1;
    }
  }
  if(N!=S || E!=W){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}