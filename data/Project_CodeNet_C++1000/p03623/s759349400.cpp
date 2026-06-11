#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X,A,B;cin>>X>>A>>B;
  if(abs(X-A)>abs(X-B)){
    cout<<'B'<<endl;
  }
  else{
    cout<<'A'<<endl;
  }
}