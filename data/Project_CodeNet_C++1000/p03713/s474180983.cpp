#include <bits/stdc++.h>
using namespace std;

int main() {
  long h,w,ans=9999999999999999;
  cin >> h >> w;
  if(h%3==0||w%3==0) {
    ans=0;
  } else {
    if(w>=3) ans=min(ans,h);
    if(h>=3) ans=min(ans,w);
    for(long i=1;i<h;i++) {
      ans=min(ans,max(w*i,(w+1)/2*(h-i))-min(w*i,w/2*(h-i)));
    }
    for(long i=1;i<w;i++) {
      ans=min(ans,max(h*i,(h+1)/2*(w-i))-min(h*i,h/2*(w-i)));
    }
  }
  cout << ans << endl;
}