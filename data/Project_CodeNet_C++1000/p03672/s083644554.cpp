#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;cin>>S;int sum=0;
  for(int X=0;X<S.size()/2-1;X++){
    string A=S.substr(0,X+1);
    string B=S.substr(X+1,X+1);
    if(A==B)sum=A.size()*2;
  }
  cout<<sum<<endl;
}