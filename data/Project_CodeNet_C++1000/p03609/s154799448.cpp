#include <bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;++i)

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int x,t;
  cin >> x >> t;
  cout << max(x-t,0) << endl;
  
  return 0;
}
