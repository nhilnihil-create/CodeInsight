#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  cout << s.size() / 2 - count(s.begin(), s.end(), 'p') << '\n';
}