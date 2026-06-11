#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  ll n = s.size();
  
  ll ans = n*(n-1)/2;
  ll alp[26]={};
  rep(i,n) alp[s[i]-'a']++;
  rep(i,26) ans -= alp[i]*(alp[i]-1)/2;
  
  cout << ans+1 << endl;
  return 0;
}