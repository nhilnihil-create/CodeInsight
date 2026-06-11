#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll Q,H,S,D,N,ans=0,Min1;
  cin >> Q >> H >>S>>D>>N;
  
  Q=Q*4;
  H=H*2;
  Min1=min({Q,H,S});
  
  if(Min1*2<D){
   ans=N*Min1;
  }
  else{
   ans=N/2*D+N%2*Min1; 
  }
  
  cout<< ans<<endl;
}