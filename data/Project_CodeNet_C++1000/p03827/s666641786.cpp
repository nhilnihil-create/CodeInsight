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
  ll N;
  string S;
  cin >> N >> S;
  ll x = 0;
  ll max_x = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'I')
      x++;
    else
      x--;
    max_x = max(max_x, x);
  }
  cout << max_x << endl;
  return 0;
}