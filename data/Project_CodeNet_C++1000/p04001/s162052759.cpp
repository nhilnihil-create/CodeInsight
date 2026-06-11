#include <bits/stdc++.h>
using namespace std;

long calc(string s) {
  long sum = 0;
  string tmp = "";
  for (int i = 0; i < s.length(); i++) {
    string t = s.substr(i, 1);
    if (t == "+") {
      sum += atol(tmp.c_str());
      tmp = "";
    } else {
      tmp += t;
    }
  }
  sum += atol(tmp.c_str());
  return sum;
}

int main() {
  bitset<9> tmp;
  
  string N;
  cin >> N;
  
  int length = N.size();
  
  long sum = 0;
  for (int i = 0; i < (1 << (length - 1)); i++) {
    string n = N;
    int offset = 0;
    for (int j = 0; j < (length - 1); j++) {
      if (i & (1 << j)) {
        n.insert((j + 1 + offset), "+");
        offset++;
      }
    }
    sum += calc(n);
  }

  cout << sum << endl;
}
