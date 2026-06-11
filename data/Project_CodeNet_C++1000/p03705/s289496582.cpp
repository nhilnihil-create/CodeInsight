#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,A,B;
  cin>>N>>A>>B;
  if(A==B)cout<<1<<endl;
  else if(N==1)cout<<0<<endl;
  else if(A>B)cout<<0<<endl;
  else{
    unsigned long long int C=(N-2)*(B-A)+1;
    cout<<C<<endl;
  }
}