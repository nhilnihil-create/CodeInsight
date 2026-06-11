#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T="CODEFESTIVAL2016";
  cin>>S;
  int j=0;
  for(int i=0;i<16;i++)
    if(S.at(i)!=T.at(i))
      j++;
  cout<<j<<endl;
}