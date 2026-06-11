# include <iostream>
using namespace std;

int main() {
  string a, b; cin >> a >> b;
  string ans;
  
  // 制約上、数値型で受け取るのは不可。文字列で受け取る。
  if (a.size() > b.size()) ans = "GREATER";
  else if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); ++i) {
      int i_a = (int) a[i], i_b = (int) b[i];
      if (i_a > i_b) {
        ans = "GREATER";
        break;
      }
      else if (i_a == i_b) continue;
      else if (i_a < i_b) {
        ans = "LESS";
        break;
      }
    }
    if (ans.empty()) ans = "EQUAL";
  }
  else if (a.size() < b.size()) ans = "LESS";
  
  cout << ans << endl;
  
  return 0;
}