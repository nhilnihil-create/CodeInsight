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
  ll n;
  cin >> n;
  vector<ll> a(n);
  deque<ll> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      q.push_back(a[i]);
    } else {
      q.push_front(a[i]);
    }
  }
  ll x;
  if (n % 2 == 0) {
    for (int i = 0; i < n; i++) {
      x = q.front();
      q.pop_front();
      cout << x << " ";
    }
  } else {
    for (int i = 0; i < n; i++) {
      x = q.back();
      q.pop_back();
      cout << x << " ";
    }
  }
  cout << endl;
  return 0;
}