#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int h,w;
  cin>>h>>w;
  
  vector<vector<char>>a(h,vector<char>(w));
  
  for(int i=0;i<h;i++){
   for(int j=0;j<w;j++){
    cin>>a.at(i).at(j); 
   }
  }
  
  for(int j=0;j<w+2;j++){
    cout<<'#';
  }
  cout<<'\n';
  
  for(int i=0;i<h;i++){
    cout<<'#';
   for(int j=0;j<w;j++){
    cout<<a.at(i).at(j); 
   }
    cout<<'#'<<endl;
  }
  for(int j=0;j<w+2;j++){
    cout<<'#';
  }
  
  return 0;
  
}