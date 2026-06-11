#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K,X,Y,S;
  cin >>N>>K>>X>>Y;
  
  if(N>=K){
  S=K*X+(N-K)*Y;
  cout <<S<<endl;}
  else{
  S=N*X;
  cout <<S<<endl;
  }
   
return 0;
}