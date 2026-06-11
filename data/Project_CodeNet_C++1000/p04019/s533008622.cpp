#include <iostream>
#include <string>
#include <set>

using namespace std;

void failure () {
  cout << "No" << endl;
  exit(0);
}

int main () {
  string s;
  cin >> s;

  set<char> cs;
  for (char c : s) {
    cs.insert(c);
  }

  if (!!cs.count('N') != !!cs.count('S')) failure();
  if (!!cs.count('E') != !!cs.count('W')) failure();
  cout << "Yes" << endl;
}
