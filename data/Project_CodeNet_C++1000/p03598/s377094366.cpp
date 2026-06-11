#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,a=0; cin>>n>>k;
  for(int i=0; i<n; i++){
    int x; cin>>x;
    a+=min(x*2,(k-x)*2);
  }
  cout<<a;
}