#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,D,a;
  cin>>A>>B>>C>>D;
  a=max(A*B,C*D);
  if(A*B==C*D){
  cout<<A*B<<endl;
  }else{
       cout<<a<<endl;
       }
}