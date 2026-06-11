#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans[26] = {false};
  for(int i = 0;i < s.size();i++){
    ans[s[i] - 'a'] = true;
  }
  if(ans[0] && ans[1] && ans[2] && ans[3] && ans[4] && ans[5] && ans[6] && ans[7] && ans[8] && ans[9] && ans[10] && ans[11] && ans[12] && ans[13] && ans[14] && ans[15] && ans[16] && ans[17] && ans[18] && ans[19] && ans[20] && ans[21] && ans[22] && ans[23] && ans[24] && ans[25] && ans[26])
      cout << "None" << endl;
  for(int i = 0;i < 26;i++){
    if(!(ans[i])){
      cout << char('a' + i) << endl;
      break;
    }
  }
}
