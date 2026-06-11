#include <bits/stdc++.h>
using namespace std;
long long n[3];
int main(){
  cin>>n[0]>>n[1]>>n[2];
  if(!(n[0]&1)||!(n[1]&1)||!(n[2]&1))return cout<<0,0;
  sort(n,n+3);
  cout<<n[0]*n[1];
}