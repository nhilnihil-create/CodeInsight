#include <bits/stdc++.h>

using namespace std;

int get_ans(string s, char c) {
  if (all_of(s.begin(), s.end(), [&](char c0) {
    return c0 == c;
  })) {
    return 0;
  }
  
  string nxt;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == c || s[i+1] == c)
      nxt += c;
    else
      nxt += s[i];
  }
  
  return get_ans(nxt, c) + 1;
}

int get_ans(string s) {
  int ans = 1e9;
  for (char c = 'a'; c <= 'z'; c++) {
    ans = min(ans, get_ans(s, c));
  }
  return ans;
}

int main() {
  char s[1000];
  scanf("%s", s);
  printf("%d\n", get_ans(s));
}