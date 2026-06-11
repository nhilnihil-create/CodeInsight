#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int pa = 0;
  int gu = 0;
  int win = 0;
  int lose = 0;
  for(int i=0;i<s.size();i++) {
    if(pa == gu) {
      gu++;
      if(s[i] == 'p') lose++;
    } else {
      pa++;
      if(s[i] == 'g') win++; 
    }
  }

  cout << win - lose << endl;
}