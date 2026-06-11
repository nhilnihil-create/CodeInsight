#include <iostream>
using namespace std;
int main(){
  int K,S;
  cin >>  K >> S;
  int ans = 0;
  for(int i=0;i<=K;i++){
  for(int j=0;j<=K;j++){
  int l = S-i-j;
    if(0<=l && l <= K){
    ans++;
    }
  
  }}
  
  cout <<  ans;
return 0;
  
}