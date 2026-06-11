#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int X,A,B;cin>>X>>A>>B;
  
  int x=abs(X-A);
  int y=abs(X-B);
  
  if(x>=y){
    cout<<'B'<<endl;
  }
  else{
    cout<<'A'<<endl;
  }
}