#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ans = max(a*b,c*d);
  cout << ans << endl;
  return 0;
}