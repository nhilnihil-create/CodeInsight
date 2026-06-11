#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;
 
int main()
{
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i, s.size()) {
    mp[s[i]]++;
  }
  string ans = "Yes";
  if ((mp['N']==0 && mp['S']!=0) || (mp['N']!=0 && mp['S']==0)) ans = "No";
  if ((mp['E']==0 && mp['W']!=0) || (mp['E']!=0 && mp['W']==0)) ans = "No";
  cout << ans << endl;
  return 0;
}