#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  int size = s.size();
  string a;
  for (int i = 0; i < size; i++) {
    if (s[i] == 'B') {
      a.pop_back();
    } else {
      a.push_back(s[i]);
    }
  }
  cout << a << endl;
  return 0;
}