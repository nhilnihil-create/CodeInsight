#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  string l="";
  cin>>h>>w;
  
  vector<string> A(h);
  
  for(int i;i<h;i++){
    cin>>A.at(i);
  }
  
  for(int i;i<w+2;i++){
    l+="#";
  }
  cout<<l<<endl;
  for(int i;i<h;i++){
    cout<<"#"+A.at(i)+"#"<<endl;
  }
  cout<<l<<endl;
}