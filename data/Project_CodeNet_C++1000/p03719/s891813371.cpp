#include <bits/stdc++.h>
using namespace std;

long long A(int x){
  long long n=2;
  for(int i=0;i<x;i++){
    n*=5;
  }
  return n;
}


int main() {
 long long a,b,c;
  cin>>a>>b>>c;
  
  if(c>=a&&c<=b){
    cout<<"Yes";
  }
  else{
  cout<<"No";
  }
  
 
}
