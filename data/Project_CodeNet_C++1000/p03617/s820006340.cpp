#include <bits/stdc++.h>
using namespace std;
int main(){
  long long q,h,s,d,n;
  cin>>q>>h>>s>>d>>n;
  h=min(2*q,h);
  s=min(2*h,s);
  cout<<n/2*min(2*s,d)+n%2*s;
}