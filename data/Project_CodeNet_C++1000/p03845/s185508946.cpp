#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int n, m, p, x, sum;
vector<int> v;

int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
    sum += x;
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> p >> x;
    cout << sum - v[p-1] + x << "\n";
  }

  return 0;
}
