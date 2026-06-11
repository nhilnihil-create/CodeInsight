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
  string S;
  cin >> S;
  int N = S.length();
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    if (S[i] != S[i - 1]) ans++;
  }
  cout << ans << endl;
}