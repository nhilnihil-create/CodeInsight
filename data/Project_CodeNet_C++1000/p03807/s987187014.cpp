#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int even = 0, odd = 0;
  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    int A; cin >> A;
    if (A % 2 == 0) even++;
    else            odd++;
  }

  if (odd % 2 == 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
