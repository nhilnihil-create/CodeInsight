#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
  int N;
  cin>>N;
  int count=0;
  for(int i=0;i<N;i++){
     int a;cin>>a;
     if(a%2>0){count++;}
  }
  if(count%2!=0){cout<<"NO"<<endl;}
  else{cout<<"YES"<<endl;}
return 0;}