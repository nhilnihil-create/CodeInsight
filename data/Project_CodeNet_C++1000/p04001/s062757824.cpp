#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num = 0;

void calc(string s) {
  int len = s.size();
  if (s.size() == 0) return;

  for (int i = 0; i < len; i++) {
    if (s[i] == '+') {
      num += stoll(s.substr(0, i));
      s.erase(s.begin(), s.begin() + i + 1);
      calc(s);
      return;
    }
  }
  num += stoll(s);
}

int main() {
  string s;
  cin >> s;
  int len = s.size();
  vector<string> ans;

  for (int bit = 0; bit < (1 << len - 1); bit++) {
    string temp = s;
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
      if ((bit >> i) & 1) {
        temp.insert(i + 1 + count, "+");
        count++;
      }
    }
    ans.push_back(temp);
  }

  for (auto it = ans.begin(); it != ans.end(); it++) {
    calc(*it);
  }
  cout << num << endl;
}