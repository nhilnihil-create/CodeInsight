#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  bool res=false;
  
  int x=0;
  
  int y=0;
  
  for(int i=0;i<N;i++){
    if(A[i]%2==1){
      x++;
    }
    else if(A[i]%4==0){
      y++;
    }
  }
  
  if(N==x+y){
    if(x<=y+1){
      res=true;
    }
  }
  else{
    if(x<=y){
      res=true;
    }
  }
  
  if(res){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}