#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int k,s;
  cin >> k >> s;
  int ans=0;
  int n=min(k,s);
  int m=max(0,s-2*k);
  for(int i=n;i>=m;i--){
    for(int j=n;j>=m;j--){
      if(0<=s-(i+j) && s-(i+j)<=k)
        ans++;
    }
  }
  cout << ans << endl;
}