#include <bits/stdc++.h>
using namespace std;

string generateFormula(string str, int i) {
  bitset<9> bit = i;
  string ret = "";
  ret += str.at(0);
  for (int i=1; i<str.size(); i++) {
    if (bit.test(i-1)) {
      ret += '+';
    }
    ret += str.at(i);
  }
  return ret;
}

int64_t solve(string f) {
  int64_t sum = 0;
  int64_t n = 0;
  for (int i=0;i<20;i++) {
    if (f.at(i) =='+') {
      sum += n;
      n = 0;
    } else {
      n = n*10 + (f.at(i)-'0');
    }
    if (f.size()-1 == i) {
      sum += n;
      break;
    }
  }
  return sum;
}

int main() {
  string str;
  cin >> str;
  
  int bitnum = (int)str.size() - 1;
  int64_t sum=0;
  for (int i = 0; i < (1 << bitnum); i++) {
    sum += solve(generateFormula(str,i));
  }
  cout << sum << endl;
}
