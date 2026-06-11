#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ans=min(b,d)-max(a,c);
  if(ans<0){
    cout << 0 << endl;
    return 0;
  }else {
    cout << ans << endl;
    return 0;
  }
}