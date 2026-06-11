#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  vector<int> cnts;
  
  cnts.push_back(cnt);
  for (int i=0; i<n; i++) {
    if (s[i] == 'I') cnt++;
    if (s[i] == 'D') cnt--;
    cnts.push_back(cnt);
  }
  
  cout << *max_element(cnts.begin(), cnts.end()) << endl;
  return 0;
}