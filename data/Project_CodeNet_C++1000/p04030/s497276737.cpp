#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

string s;
int n;
vector<char> ans;

int main() {

  getline(cin, s);
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      if (!ans.empty()) ans.pop_back();
    } else {
      ans.push_back(s[i]);
    }
  }
  n = ans.size();
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }

  return 0;
}