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
  string w;
  cin >> w;

  map<char, int> dic;

  for (int i = 0; i < w.size(); i++) {
    dic[w[i]]++;
  }

  for (auto& p : dic) {
    if (p.second % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}