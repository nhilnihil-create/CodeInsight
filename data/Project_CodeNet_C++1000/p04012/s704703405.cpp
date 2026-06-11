#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main() {
  int cnt[26] = {};
  string w;
  cin >> w;
  for (int i=0; i < w.length(); i++) {
    cnt[w[i]-'a']++;
  }
  for (int i=0; i < 26; i++) {
    if (cnt[i]%2) { cout << "No" << endl; return 0;}
  }
  cout << "Yes" << endl;
  return 0;
}
