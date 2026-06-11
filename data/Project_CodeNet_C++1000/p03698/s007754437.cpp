#include<bits/stdc++.h>
using namespace std;
int main(){
  string z;
  cin>>z;
  int x=z.length(),y;
  vector<int> w(26);
  for(y=0;y<x;y++){
    w.at(z.at(y)-'a')++;
    if(w.at(z.at(y)-'a')==2){
      cout<<"no"<<endl;
      return 0;
    }
  }
  cout<<"yes"<<endl;
}