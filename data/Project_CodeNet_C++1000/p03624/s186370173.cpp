#include <bits/stdc++.h>
using namespace std;

int main() {
  string str; cin >> str;
  
  char ch = 'a';
  string ans = "None";
  while(ch <= 'z') {
    if(str.find(ch) == string::npos) {
    	ans = ch;
	    break;
    }
    ch++;
  }
  
  cout << ans << endl;

  return 0;
}
