#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
constexpr i32 INF = 1 << 30;

int main()
{
  i32 x, a, b;
  cin >> x >> a >> b;
  cout << (abs(x - a) > abs(x - b) ? 'B' : 'A');
  return 0;
}
