#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K,L=0;
  cin>>N>>K;
  for(int i=0;i<N;i++){
  	int x,a;
    cin>>x;
    a = abs(x-K);
   // cout<<a<<endl;
    if(x<=a){
    	L+=x*2;
    }//if
    else{
    	L+=a*2;}
  //cout<<i<<":"<<L<<endl;
  }//for
  cout<<L<<endl;
}