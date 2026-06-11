#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  int A=a+11;
  int B=b+11;
  if (A%13>B%13){
    cout<<"Alice"<<endl;
  }
  else if (A%13==B%13){
    cout<<"Draw"<<endl;
  }
  else{
    cout<<"Bob"<<endl;
  }
  
}