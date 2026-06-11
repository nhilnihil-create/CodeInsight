#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  string s;
  cin >> s;
  s = "$"+s;
  cerr << s << endl;
  vector<vector<int>> L(s.length(),vector<int>(26,-1));
  for(size_t i = s.length()-1; i > 0; --i){
    L[i-1] = L[i];
    L[i-1][s[i]-'a'] = i;
  }
  vector<vector<int>> D(s.length(),vector<int>(26));
  vector<int> E(s.length());
  for(size_t i = s.length()-1; i < s.length(); --i){
    for(int j = 0; j < 26; ++j){
      if(L[i][j] < 0) continue;
      D[i][j] = E[L[i][j]];
    }
    if(i == 0) continue;
    int t = *min_element(D[i].begin(), D[i].end());
    E[i] = t+1;
  }
  string ans;
  int idx = 0;
  while(1){
    int mi = *min_element(D[idx].begin(), D[idx].end());
    for(int i = 0; i < 26; ++i){
      if(D[idx][i] > mi) continue;
      ans += 'a'+i;
      idx = L[idx][i];
      break;
    }
    if(idx < 0) break;
  }
  cout << ans << endl;
}
