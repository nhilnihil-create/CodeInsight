#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<vector<ll>> matrix;

ll l[100005];
ll diff[100005];
void solve() {
  int n;
  cin >> n;
  ll totalSum = 0;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    totalSum += l[i];
  }
  ll sumInOne = n*(n+1LL) / 2;
  if(totalSum % sumInOne) {
    cout << "NO\n";
    return;
  }
  ll expectedIncOps = totalSum / sumInOne;
  for(int i = 0; i < n; i++) {
    diff[i] = (l[(i+1)%n] - l[i]);
  }
  int desiredIncOps = 0;
  for(int i = 0; i < n; i++) {
    diff[i] -= expectedIncOps;
    if(diff[i] % n || diff[i] > 0) {
      cout << "NO\n";
      return;
    }
    desiredIncOps -= diff[i] / n;
  }
  if(expectedIncOps != desiredIncOps) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
