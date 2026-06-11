#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  vector<ll> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  cout << a[0] + a[1] << endl;
  return 0;
}