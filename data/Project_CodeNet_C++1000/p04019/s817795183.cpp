# include <iostream>
using namespace std;

int main() {
  string s, ans = "No"; cin >> s;
  int n_cnt = 0, w_cnt = 0, s_cnt = 0, e_cnt = 0;
  
  for (int i = 0; i < s.size(); ++i) {
    char direction = s[i];
    if (direction == 'N') ++n_cnt;
    else if (direction == 'W') ++w_cnt;
    else if (direction == 'S') ++s_cnt;
    else if (direction == 'E') ++e_cnt;
  }
  
  if (n_cnt > 0 && s_cnt > 0 && w_cnt > 0 && e_cnt > 0) ans = "Yes";
  else if (n_cnt == 0 && s_cnt == 0 && w_cnt > 0 && e_cnt > 0) ans = "Yes";
  else if (n_cnt > 0 && s_cnt > 0 && w_cnt == 0 && e_cnt == 0) ans = "Yes";
  
  cout << ans << endl;
  
  return 0;
}