#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    if (!item.empty()) {
      elems.push_back(item);
    }
  }
  return elems;
}

int largest(const vector<string> &ss) {
  int result = 0;
  for (const string & s : ss) {
    result = max(result, (int)s.size());
  }
  return result;
}

int main(void) {
  string s;
  cin >> s;

  int result = 999;
  for (int i = 0; i < 26; i++) {
    vector<string> part = split(s, i + 'a');
    result = min(result, largest(part));
  }

  cout << result << endl;
  return 0;
}