#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (char c = 'a'; c <= 'z'; c++) {
    int left[s.length()], right[s.length()], x, a = 1, b = s.length();
    left[0] = INT_MIN;
    right[s.length()-1] = INT_MIN;
    for (int i = 1; i < s.length(); i++) {
      if (s[i-1] == c) {
        left[i] = 1;
      } else {
        left[i] = left[i-1]+1;
      }
    }
    x = s.back() == c;
    for (int i = s.length()-2; i+1; i--) {
      x += s[i] == c;
      if (s[i+1] == c) {
        right[i] = 1;
      } else {
        right[i] = right[i+1]+1;
      }
    }
    while (a < b) {
      if (2*x > b-a+1) {
        cout << a << ' ' << b;
        return 0;
      } else if (s[a-1] == c && s[b-1] != c) {
        b--;
      } else if (s[a-1] != c && s[b-1] == c) {
        a++;
      } else if (s[a-1] != c && s[b-1] != c) {
        a++;
        b--;
      } else if (left[b-1] > right[a-1]) {
        b--;
        x--;
      } else {
        a++;
        x--;
      }
    }
  }
  cout << "-1 -1";
}