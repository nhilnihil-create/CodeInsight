#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,m;
  cin>>n>>m;
  m/=2;
  if(n>=m) cout<<m;
  else cout<<n+(m-n)/2;
}