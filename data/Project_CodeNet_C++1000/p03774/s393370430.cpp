#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
  int n,m;
  cin>>n>>m;
  
  vector<vector<int>>pos(2,vector<int>(n));
  vector<vector<int>>check(2,vector<int>(m));
  
  for(int i=0;i<n;i++){
   cin>>pos.at(0).at(i)>>pos.at(1).at(i); 
  }
  for(int i=0;i<m;i++){
   cin>>check.at(0).at(i)>>check.at(1).at(i); 
  }
  
  for(int i=0;i<n;i++){
    int x,y;
    int ans=0;
    x=fabs(pos.at(0).at(i)-check.at(0).at(0))+fabs(pos.at(1).at(i)-check.at(1).at(0));
     for(int j=1;j<m;j++){
       y=fabs(pos.at(0).at(i)-check.at(0).at(j))+fabs(pos.at(1).at(i)-check.at(1).at(j));
       if(y<x){
         x=y;
         ans=j;
       }
     }
    cout<<ans+1<<endl;
  }
  return 0;
}