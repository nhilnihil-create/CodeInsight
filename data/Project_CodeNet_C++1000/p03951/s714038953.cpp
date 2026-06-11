#include <iostream>
using namespace std;

int main() {
  int n; cin>>n;
  string s; cin>>s;
  string t; cin>>t;
  for(int i=0;i<=n;i++) {
    if (s.substr(i,n-i)==t.substr(0,n-i)) {
      cout<<n+i<<endl;
      return 0;
    }
  }
}