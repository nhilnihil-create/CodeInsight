#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int k; string s;
  cin >> s >> k;
  rep(i, s.size()){
    if(i == (int)s.size()-1) s[i] = (char)((s[i]+k-'a')%26 + 'a');
    else if(s[i] != 'a' && k >= 26-s[i]+'a'){
      k -= 26-s[i]+'a';
      s[i] = 'a';
    }
  }
  cout << s << "\n";
  return 0;
}