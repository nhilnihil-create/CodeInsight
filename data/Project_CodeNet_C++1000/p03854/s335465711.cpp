#include <bits/stdc++.h>
using namespace std;

int main() {
  string sample[4] = {"dream","dreamer","erase","eraser"};
  string s; cin >> s;
  reverse(s.begin(), s.end());
  for (int i = 0; i < 4; i++) reverse(sample[i].begin(), sample[i].end());
  bool count1 = true;
  for (int i = 0; i < s.size(); ){
    bool count2 = false;
    for (int j = 0; j < 4; j++){
      string xxx = sample[j];
      if (s.substr(i, xxx.size()) == xxx){
        count2 = true;
        i += xxx.size();
      }
    }
    if (!count2){
      count1 = false;
      break;
    }
  }
  if (count1) cout << "YES" << endl;
  else cout << "NO" << endl;
}


