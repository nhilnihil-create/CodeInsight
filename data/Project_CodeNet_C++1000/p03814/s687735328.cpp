#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int left;
  int right;
  bool flag = false;
  
  cin >> s;
  for(int i=0;i<s.size();++i){
    if(s.at(i) == 'A' && !flag){
      left = i;
      flag = true;
    }

    if(s.at(i) == 'Z' && flag) right = i;
  }

  cout << right - left + 1 << endl;
  return 0;
}
