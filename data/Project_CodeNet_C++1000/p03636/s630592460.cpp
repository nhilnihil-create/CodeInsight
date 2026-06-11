#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  string a;
  cin >> a;
  int b = a.size();
  cout << a.at(0) << b-2 << a.at(b-1);
}