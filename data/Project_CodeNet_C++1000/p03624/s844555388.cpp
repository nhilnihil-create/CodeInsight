#include<bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;
  
  map<char,int> x;
  for (int i = 0; i < s.size(); i++) {
    if (!x.count(s[i])) {
      x[s[i]] = 0;
    }
    if (x.size() == 26) {
      cout << "None" << endl;
      return 0;
    }
  }
  for (char i = 'a'; i <= 'z'; i++) {
    if (!x.count(i)) {
      cout << i << endl;
      return 0;
      
    }
  }
}