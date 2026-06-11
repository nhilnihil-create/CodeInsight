#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
  
int main(){
  string s; cin >> s;
  string ans = "";
  int N = s.size();
  rep(i,N) {
    int ansN = ans.size();
    if (s[i] == '0') ans = ans + '0';
    if (s[i] == '1') ans = ans + '1';
    if (s[i] == 'B' && ansN != 0) ans.erase(ansN-1);
  }
  
  cout << ans << endl;
}