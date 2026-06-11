#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n){
    int in;
    cin >> in;
    mp[in-1]++;
    mp[in]++;
    mp[in+1]++;
  }
  int ans = 0, mx = 0;
  repit(itr, mp){
    if(itr->second > mx){
      ans = itr->first;
      mx = itr->second;
    }
  }
  cout << mx << endl;
  return 0;
}