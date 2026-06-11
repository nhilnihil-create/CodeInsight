#include <bits/stdc++.h>
using namespace std;

string plus_all(string s) {
  int ssize = s.size();
  int64_t sum = 0;
  int64_t tmp = 0;
  for (int f = 0; f < (1 << ssize-1); f++) {
    bitset<10> flag(f);
    flag <<= 1;
    for (int i = 0; i < ssize; i++) {
      if (flag.test(ssize - 1 - i) == true) {
        tmp += (s[i] - '0');
        tmp *= 10;
      } else {
        tmp += (s[i] - '0');
        sum += tmp;
        tmp = 0;
      }
    }
  }
  return to_string(sum);
}


int main() {
  string s;
  cin >> s;
  cout << plus_all(s) << endl;
}
