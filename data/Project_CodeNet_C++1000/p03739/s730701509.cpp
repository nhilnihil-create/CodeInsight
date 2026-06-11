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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll s1=0,s2=0;
  ll ans1=0,ans2=0;
  rep(i,n){
    s1 += a[i];
    if(i%2){
      if(s1>=0) ans1+=s1+1, s1=-1;
    }else{
      if(s1<=0) ans1+=1-s1, s1=1;
    }
  }
  rep(i,n){
    s2 += a[i];
    if(i%2){
      if(s2<=0) ans2+=1-s2, s2=1;
    }else{
      if(s2>=0) ans2+=s2+1, s2=-1;
    }
  }
  cout << min(ans1,ans2) << endl;
}
