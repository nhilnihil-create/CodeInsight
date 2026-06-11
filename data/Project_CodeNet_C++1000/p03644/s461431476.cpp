#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int X;cin>>X;
  
  int p;
  
  for(int i=6;i>=0;i--){
    if(pow(2,i)<=X){
      p=i;
      break;
    }
  }
  
  for(int i=100;i>=0;i--){
    if(pow(2,p)*i<=X){
      cout<<pow(2,p)*i<<endl;
      return 0;
    }
  }
}