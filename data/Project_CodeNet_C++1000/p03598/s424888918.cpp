#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  int x;
  
  cin >> N >> K;
  
  int d=0;
  
  for(int i=0;i<N;i++){
    
    cin >> x;
    
    if(abs(x) <= abs(x-K)){
      d=d+x*2;
    }
    else{
      d=d+(abs(x-K))*2;
    }
  }
  
  cout << d << endl;
}