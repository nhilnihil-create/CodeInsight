#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N = 0,ans = 0;
  cin >> N;
  map<ll, ll> mp;
  rep(i,N){
    ll tmp = 0;
    cin >> tmp;
    mp[tmp]++;
  }
  for (auto p : mp){
    if(p.second % 2 != 0){
      ans++;
    }
  }
  cout << ans;
}