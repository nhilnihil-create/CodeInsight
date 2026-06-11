#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int64_t sum = 0;
  
  for (int i = 0; i < 1 << (s.size() - 1); i++) {
    bitset<10> b(i);
    string tmp = "";
    
    for (int j = 0; j < s.size(); j++) {
      tmp += s.at(j);
      
      if (b.test(j)) {
        sum += stoll(tmp);
        tmp = "";
      }
    }
    
    sum += stoll(tmp);
  }
  
  cout << sum << endl;
}
