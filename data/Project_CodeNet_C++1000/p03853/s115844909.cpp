#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  
  vector<vector<char>>c(w,vector<char>(h));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c.at(j).at(i);
    }
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<w;k++){
        cout<<c.at(k).at(i);
      }
  	  cout<<endl;
    }
  }
  
  return 0;
}