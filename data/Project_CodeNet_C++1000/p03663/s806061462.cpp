#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

bool ask(ll n) {
  cout << "? " << n << endl;
  char ans;
  cin >> ans;
  return (ans == 'Y');
}

int findLength() {
  ll cur = 10;
  for (int len = 2; len <= 11; len++) {
    if (!ask(cur)) {
      return len - 1;
    }
    cur *= 10;
  }
  cur = 9;
  for (int len = 1; len <= 10; len++) {
    if (ask(cur)) {
      return len;
    }
    cur = cur * 10 + 9;
  }
  return -1;
}

int main() {
  int len = findLength();
  ll cur = 0;
  for (int i = 1; i <= len; i++) {
    int low = -1, high = 9;
    if (cur == 0) {
      ++low;
    }
    // (low, high]
    while (high - low > 1) {
      int mid = (high + low) / 2;
      ll n = cur * 10 + mid;
      for (int j = i; j < len + 1; j++) {
        n = n * 10 + 9;
      }
      if (ask(n)) {
        high = mid;
      } else {
        low = mid;
      }
    }
    cur = cur * 10 + high;
  }
  cout << "! " << cur << endl;
  return 0;
}
