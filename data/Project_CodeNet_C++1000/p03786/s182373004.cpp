#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll sum = a[0];
  ll b = 0;
  for(int i = 1; i < n; i++) {
    if(sum * 2 < a[i]) {
      b = i;
    }
    sum += a[i];
  }
  cout << n - b << endl;
  return 0;
}