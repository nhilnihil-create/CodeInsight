#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

long long x, a, b, ans;

int main() {

  cin >> a >> b >> x;
  ans = b/x - a/x;
  if (a%x == 0) ans++;
  cout << ans;

  return 0;
}
