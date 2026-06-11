#include <bits/stdc++.h>
using namespace std;

int main() {
  long ans,a=0;
  string x;
  cin >> x;
  ans=x.size();
  for(long i=0;i<x.size();i++) {
    if(x[i]=='S') {
      a++;
    } else {
      if(a>0) {
        a--;
        ans-=2;
      }
    }
  }
  cout << ans << endl;
}