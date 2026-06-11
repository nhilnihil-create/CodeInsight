#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll h,w;
  cin >> h >> w;
  if(h%3==0||w%3==0){
    cout << 0 << endl;
    return 0;
  }
  ll ans = h*w;
  rep(_,2){
    rep(i,h-1){
      ll h1=i+1,h2=h-1-i;
      ll s1=h1*w, s2=w/2*h2, s3=(w+1)/2*h2;
      ans = min(ans,max(s1,s3)-min(s1,s2));
      if(h2>1){
        s2=h2/2*w, s3=(h2+1)/2*w;
        ans = min(ans,max(s1,s3)-min(s1,s2));
      }
    }
    swap(h,w);
  }
  cout << ans << endl;
}
