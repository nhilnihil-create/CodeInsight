#include <bits/stdc++.h>

using namespace std;

int main(void){
  string s;
  cin >> s;
  int l = s.size();
  printf("%c%d%c\n", s[0], l-2, s[l-1]);
}