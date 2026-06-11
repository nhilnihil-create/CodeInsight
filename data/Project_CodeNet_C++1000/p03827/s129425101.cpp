#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int x, maxi, n;
string s;

int main() {

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'I') x++;
    else x--;
    if (x > maxi) maxi = x;
  }

  cout << maxi;

  return 0;
}
