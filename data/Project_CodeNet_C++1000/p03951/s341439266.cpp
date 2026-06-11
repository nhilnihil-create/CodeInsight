#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s,t;
  cin>>n>>s>>t;
  if(s==t) {
    cout<<n<<"\n";
    return 0;
  }
  int l = 0;
  for(int i=0; i<n; i++) {
    if(s.substr(n-i)==t.substr(0,i)) l = max(l,i);
  }
  cout<<2*n - l<<"\n";
}