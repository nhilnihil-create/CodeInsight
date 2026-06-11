#include<bits/stdc++.h>
using namespace std;
int main(){
string A,B,C;
  cin>>A>>B>>C;
  int N=A.size();
  int M=B.size();
  if(A.at(N-1)!=B.at(0))
    cout<<"NO"<<endl;
  else{
  if(B.at(M-1)!=C.at(0))
    cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }
   return 0;
}