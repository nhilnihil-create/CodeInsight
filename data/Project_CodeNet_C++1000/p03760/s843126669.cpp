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
  string o, e;
  cin >> o >> e;

  string a[110];

  int o_size = o.size();
  int e_size = e.size();

  int o_current = 0;
  for (int i = 0; i < o_size; i++) {
    a[o_current] = o[i];
    o_current += 2;
  }
  int e_current = 1;
  for (int i = 0; i < e_size; i++) {
    a[e_current] = e[i];
    e_current += 2;
  }

  for (int i = 0; i < o_size+e_size; i++) {
    cout << a[i];
  }
  cout << endl;
  return 0;
}