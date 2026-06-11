#include <bits/stdc++.h>
using namespace std;

char buf[114514];
string s1;
string s2;

int main() {
  scanf("%s", buf);
  s1 = buf;

  map<char, char> rev;
  rev['b'] = 'd';
  rev['d'] = 'b';
  rev['p'] = 'q';
  rev['q'] = 'p';
  for (int i=s1.size()-1; i>=0; i--) {
    s2 += rev[s1[i]];
  }

  if (s1 == s2) puts("Yes");
  else puts("No");
}
