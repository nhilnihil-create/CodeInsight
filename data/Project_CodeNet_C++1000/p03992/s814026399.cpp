#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  string s;
  cin >> s;
  for (int i = 0; i < 12; i++) {
    if (i == 4) {
      cout << " ";
    }
    cout << s[i];
  }
  cout << endl;
  return 0;
}
