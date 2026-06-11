#include <bits/stdc++.h>
using namespace std;

int main() {
  string str; cin >> str;
  
  string checked = "";
  string ans = "yes";
  for(int i = 0; i < str.size(); i++) {
    char temp = str.at(i);
    if(checked.find(temp) != string::npos) {
		ans = "no";
        break;
    }
    checked += temp;
  }
  
  cout << ans << endl;
  
  return 0;
}