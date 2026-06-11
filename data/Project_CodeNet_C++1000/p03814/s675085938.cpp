#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int st = 0, ed = s.size() - 1;
  while (s[st] != 'A') {
    st++;
  }
  while (s[ed] != 'Z') {
    ed--;
  }
  
  cout << ed - st + 1<< endl;
}
