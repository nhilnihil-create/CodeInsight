#include<bits/stdc++.h>
using namespace std;

int main(){

  long long N, b, i;
  cin>>N;
  map<long long, long long> B;
  
  
  for(i=0; i<N; i++){
    cin>>b;
    B[b]++;
  }
  
  long long mx1=0, mx2=0;
  for(auto p : B){
    if(p.second>=4){
      if(mx1<p.first){
        mx1 = p.first;
        mx2 = mx1;
      }else if(mx2<p.first){
        mx2 = p.first;  
      }
    }else if(p.second>=2){
      if(mx1<p.first){
        mx2 = mx1;
        mx1 = p.first;
      }else if(mx2<p.first){
        mx2 = p.first;
      }
    }
  }
  cout << mx1*mx2 << endl;
  return 0;
}