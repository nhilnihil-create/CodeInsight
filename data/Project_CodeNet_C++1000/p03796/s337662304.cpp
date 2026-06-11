#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
main(){
  long long n,ans=1;cin >> n;
  int cc=1000000007;
  for(int i=1;i<=n;i++){
    ans = (ans*i)%cc;
  }
  cout << ans << endl;
  return 0;
}