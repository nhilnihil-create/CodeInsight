#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i, s.size()){
    mp[s[i]]++;
  }
  string ans = "Yes";
  rep(i, s.size()){
    if(mp[s[i]] % 2) ans = "No";
  }
  
  cout << ans << endl;
    
  return 0;
}
