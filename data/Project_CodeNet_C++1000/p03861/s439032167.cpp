#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
main(){
  long long a,b,x;cin >> a >> b >> x;
  long long ans = 0;
  if(a == 0){
    ans+=b/x+1;
  } else {
    ans+=b/x+1 - (a-1)/x-1;
  }
  cout << ans << endl;
  return 0;
}

