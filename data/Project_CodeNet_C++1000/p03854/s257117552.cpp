#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  reverse(s.begin(), s.end());
  string tmp = "";
  int cnt = 0;
  for(const auto& e: s) {
    tmp = e + tmp;
    if(tmp == "dream" || tmp == "dreamer" || tmp == "erase" || tmp == "eraser") {
      cnt += tmp.size();
      tmp = "";
    }
  }
  
  if(cnt == s.size()) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}