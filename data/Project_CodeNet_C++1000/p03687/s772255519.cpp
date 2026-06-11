#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
  
int main(){
  string s;
  cin >> s;
  int min_ans = 1000;
  bool judge;
  
  // setを使って判定してみる。
  set<char> chars;
  rep(i, s.size() - 1){
    chars.insert(s[i]);
  }
  
  if (chars.size() == 1 || s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (auto key = chars.begin() ; key != chars.end(); ++key){
    bool flag = true;
    string str = s;
    int times = 1;
      while (flag) {
      	string vacant;
        flag = false;
        rep(i, str.size() - 1){
          if (str[i] == *key || str[i+1] == *key) vacant += *key;
          else vacant += str[i], flag = true;
        }
      
        if (flag){
          str = vacant;
          times++;
        }
      }
      min_ans = min(min_ans, times);
    }
  cout << min_ans << endl;
  return 0;
}
