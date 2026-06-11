#include<bits/stdc++.h>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  int a = s.size() - 2;
  int b = s.size();
  char c = s[0],d = s[b-1];
  cout << c << a << d << endl;
}