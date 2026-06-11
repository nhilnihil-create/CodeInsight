#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long n,a=1,m; cin>>n;
  m=pow(10,9)+7;
  for(int i=1; i<=n; i++){
    a*=i;
    if(a>m) a%=m;
  }
  cout<<a;
}