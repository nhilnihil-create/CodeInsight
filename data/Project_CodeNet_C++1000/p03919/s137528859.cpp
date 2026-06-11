#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	  string str; cin >> str;
	  if (str == "snuke") a = i, b = j;
	}
  }
  cout << (char)('A'+b) << a+1 << endl;
}
