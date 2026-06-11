#include <iostream>
using namespace std;
int main(){
  int ans=2;
  int N;
  cin>>N;
  if(N==1){
  cout<<1;
  return 0;
  }
  else{
  while(ans<=N){
  ans*=2;
  }
    cout<<ans/2;
  }
}