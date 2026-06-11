#include <bits/stdc++.h>
using namespace std;

int main() {
  string A,B,C; 
  cin >>A>>B>>C;
  int kazuA=A.size();
  int kazuB=B.size();
  if(A[kazuA-1]==B[0]&&B[kazuB-1]==C[0]){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}