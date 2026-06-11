#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  vector<int64_t> vecA(N);
  vector<int64_t> vecB(N);
  for(int i=0;i<N;i++){
    cin>>vecA.at(i)>>vecB.at(i);
  }
  int64_t kai=0;
  int64_t rui=0;
  for(int i=N-1;i>=0;i--){
    int64_t son;
    if(vecA.at(i)+rui>=vecB.at(i)){
      son=(((vecA.at(i)+rui)+vecB.at(i)-1)/vecB.at(i))*vecB.at(i)-vecA.at(i)-rui;
    }
    else{
      if(vecA.at(i)+rui==0) son=0;
      else son=vecB.at(i)-vecA.at(i)-rui;
    }
    kai+=son;
    rui+=son;
  }
  cout<<kai<<endl;
    
  
  
  
  
}