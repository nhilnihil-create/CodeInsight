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
  rep(i, s.size()) mp[s[i]]++;
  char c;

  for(int i = 0; i < 26; i++) {
    c = 'a' + i;
    if(mp[c] == 0) {
      cout << c << endl;
      return 0;
    }
  }
  

  cout << "None" << endl;
  return 0;
}
