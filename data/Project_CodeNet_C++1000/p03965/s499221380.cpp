#include <bits/stdc++.h>
using namespace std;

const char ROCK = 'g';
const char PAPER = 'p';

int main() {
  string s;
  cin >> s;
  cout << s.size() / 2 - count(s.begin(), s.end(), PAPER) << endl;
}
