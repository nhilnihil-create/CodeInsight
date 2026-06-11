#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,M;
  cin >>N>>M;
  
  ll S=1;
  for(int i=0;i<N;i++){
    if(i==0){
      S*=M;
    }
    else{
      S*=M-1;
    }
  }
  
  cout << S <<endl;
}
