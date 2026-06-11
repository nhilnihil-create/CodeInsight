#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  string s;
  int k;
  cin >> s >> k;
  int i = 0, sz = s.size();
  while(k>0&&i<sz) {
    int x = 'z' -s[i] + 1;
    if(x<=k&&x<26) {
      s[i] = 'a';
      k -= x;
    }
    i++;
  }
  // if(k>0) s[sz-1] = (char)(s[sz-1]+k);
  s[sz-1] += k%26;
  cout << s << endl;
  return 0;
}