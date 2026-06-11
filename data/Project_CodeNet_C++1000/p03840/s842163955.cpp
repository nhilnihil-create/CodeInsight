#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll I, O, T, J, L, S, Z, xx, jil=0;
  cin>>I>>O>>T>>J>>L>>S>>Z;
  xx=(I/2+J/2+L/2)*2;
  if(I>0&&J>0&&L>0){
    jil=3;I--;J--;L--;
  }
  jil+=(I/2+J/2+L/2)*2;
  cout<<max(xx,jil)+O<<endl;
}