#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

ifstream fin("../data.txt");

string s;
int stones, n;

int main() {

  getline(cin, s);
  n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i-1]) stones++;
  }

  cout << stones;

  return 0;
}
