#include <bits/stdc++.h>
using namespace std;

// これ以降の行は変更しなくてよい


int main() {
  string s;
  cin >> s;
  vector<string> div = {"dream", "dreamer", "erase", "eraser" };
  reverse(s.begin(), s.end());
  for (int i = 0; i < 4; i++) reverse(div.at(i).begin(), div.at(i).end());

  for (int i = 0; i < s.size();) {
    for (int j = 0; j < 4; j++) {
      if(s.substr(i, div.at(j).size()) == div.at(j)){
        i += div.at(j).size();
        break;
      }
      if(j == 3){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
