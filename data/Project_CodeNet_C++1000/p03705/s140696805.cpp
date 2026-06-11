#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int64_t N,A,B;
  cin>>N>>A>>B;
  
  if(N==1&&A!=B){cout<<0<<endl;}
  else if(N==1&&A==B){cout<<1<<endl;}
  else if(N>1&&A>B){cout<<0<<endl;}
  else if(N>1&&A<=B){
  cout<<(N-2)*(B-A)+1<<endl;}
  return 0;}