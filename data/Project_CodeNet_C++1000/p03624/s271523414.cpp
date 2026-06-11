#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  vector<bool> app(26);
  rep(i, s.size()) app[s[i] - 'a'] = true;
  rep(i, 26) if(!app[i]) {
    printf("%c\n", char(i + 'a'));
    return 0;
  }
  
  printf("None\n");
  return 0;
}