#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

string s;
vector<int> v(26);
int n;

int main() {

  getline(cin, s);
  n = s.size();

  for (int i = 0; i < n; i++) {
    v[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (v[i] % 2) {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";
  return 0;
}
