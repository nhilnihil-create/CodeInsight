#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int n;cin>>n;
  string s,t;cin>>s>>t;
  for(int i=n;i>0;i--)
    if(s.substr(n-i,i)==t.substr(0,i))
      fin(2*n-i);
  fin(n+n);
}
