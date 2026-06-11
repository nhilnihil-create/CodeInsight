#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#define ill long long
#define rep(i, a, b) for(ill i = (ill)(a); i < (ill)(b); i++)
#define fcout cout << fixed << setprecision(10)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> v = {0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
  if(v[a-1] == v[b-1]) cout << "Yes\n";
  else cout << "No\n";
}
