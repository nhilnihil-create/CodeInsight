#include<bits/stdc++.h>
using namespace std;
int main(){
  int A[3]; cin>>A[0]>>A[1]>>A[2];
  sort(A,A+3);
  string ans="NO";
  if(A[0]==A[1]&&A[1]==5&&A[2]==7) ans="YES";
  cout<<ans<<endl;
}