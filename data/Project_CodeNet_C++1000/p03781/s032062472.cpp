#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1000000000
#define MOD 1000000007
#define mod(x) ((x % MOD) + MOD) % MOD

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
  ll X;
  cin >> X;

  ll i = 0;

  while (true) {
    if (i * (i + 1) / 2 >= X) {
      cout << i << endl;
      break;
    }
    i++;
  }
  return 0;
}
