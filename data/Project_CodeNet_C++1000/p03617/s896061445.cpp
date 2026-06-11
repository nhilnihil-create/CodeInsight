#include<bits/stdc++.h>
using namespace std;
int main(){
  long long q, h, s, d;
  long long N;
  cin>>q>>h>>s>>d>>N;
  long long ONE=min(4*q,min(2*h,min(2*q+h,s)));
  long long TWO=min(d,ONE*2);
  cout<<N/2*TWO+N%2*ONE<<endl;
}