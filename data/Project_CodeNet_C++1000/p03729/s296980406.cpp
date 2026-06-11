#include<iostream>
#include<string>
using namespace std;
int main(){

  string A,B,C;
  cin>>A>>B>>C;
  if(A[A.length()-1]!=B[0]){
  
    cout<<"NO";
    return 0;
  }
  if(B[B.length()-1]!=C[0]){
  
    cout<<"NO";
    return 0;
  }
  cout<<"YES";
  return 0;
}