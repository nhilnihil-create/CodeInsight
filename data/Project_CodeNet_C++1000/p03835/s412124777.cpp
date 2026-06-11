#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int k, s, x, y, z, ways;

int main() {

  cin >> k >> s;

  for (x = 0; x <= k; x++) {
    for (y = 0; y <= k; y++) {
      if (s - x - y >= 0 && s - x - y <= k) ways++;
    }
  }
  cout << ways;
  return 0;
}
